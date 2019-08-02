#pragma once
#include <utility>
namespace RAII {

template <typename Provider>
    class Booking{
    public:
        Booking() = default;
        Booking(Provider* p, int c): provider_(p), counter_(c) {}
        
        
        Booking(const Booking&) = delete;
        Booking& operator=(const Booking&) = delete;
        
        
        Booking(Booking&& other){
            std::swap(provider_, other.provider_);
            std::swap(counter_, other.counter_);
        }

        Booking& operator=(Booking&& other){
            if (provider_)
                provider_->CancelOrComplete(*this);
            
            provider_= other.provider_;
            counter_ = other.counter_;
            
            other.provider_ = nullptr;
            other.counter_ = 0;
            
            return *this;
        }


        ~Booking(){
            if (provider_)
                provider_->CancelOrComplete(*this);
        }
    private:
        Provider* provider_ = nullptr;
        int counter_ = 0;
    };
    

}
