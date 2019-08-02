#include "Common.h"
#include <unordered_map>
#include <list>
#include <mutex>
#include <algorithm>

using namespace std;

class LruCache : public ICache {
public:
    using Priority = size_t;
    using BookTitle = string;
    
  LruCache(
      shared_ptr<IBooksUnpacker> books_unpacker,
      const Settings& settings
           ): books_unpacker_(books_unpacker), settings_(settings) {
  }

  BookPtr GetBook(const string& book_name) override {
      lock_guard g(locker);
      
      auto book_it = cache.find(book_name);
      if (book_it == cache.end()){
          BookPtr book = books_unpacker_->UnpackBook(book_name);
          total_memory_ += book->GetContent().size();
          cache_data.emplace_front(book);
          cache.insert({book_name, cache_data.begin()});
      } else{
          BookCachePtr it = book_it->second;
          cache_data.push_front(move(*it));
          cache_data.erase(it);
          book_it->second = cache_data.begin();
      }
      BookPtr result = cache_data.front();
      CleanUpCache();
      return result;      
  }
private:
    
    using BookCachePtr = list<BookPtr>::iterator;
    size_t total_memory_ = 0;
    
    shared_ptr<IBooksUnpacker> books_unpacker_;
    Settings settings_;
    list<BookPtr> cache_data;
    unordered_map<BookTitle, BookCachePtr> cache;
    mutex locker;
    
    void CleanUpCache(){
        while (total_memory_ > settings_.max_memory){
            BookPtr book = cache_data.back();
            total_memory_ -= book->GetContent().size();
            cache.erase(book->GetName());
            cache_data.pop_back();
        }
    }
};


unique_ptr<ICache> MakeCache(
    shared_ptr<IBooksUnpacker> books_unpacker,
    const ICache::Settings& settings
) {
    return make_unique<LruCache>(move(books_unpacker), settings);
}
