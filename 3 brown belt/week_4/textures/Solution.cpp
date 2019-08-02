#include "Common.h"
#include "Textures.h"
#include <algorithm>

using namespace std;

// Этот файл сдаётся на проверку
// Здесь напишите реализацию необходимых классов-потомков `IShape`

class Rectangle: public IShape {
public:
    virtual ~Rectangle() = default;
    
    // Возвращает точную копию фигуры.
    // Если фигура содержит текстуру, то созданная копия содержит ту же самую
    // текстуру. Фигура и её копия совместно владеют этой текстурой.
    std::unique_ptr<IShape> Clone() const override {
        return make_unique<Rectangle>(*this);
    }
    
    void SetPosition(Point new_position) override {
        position = new_position;
    }
    Point GetPosition() const override {
        return position;
    }
    
    void SetSize(Size new_size) override {
        size_ = new_size;
    }
    Size GetSize() const override {
        return size_;
    }
    
    void SetTexture(std::shared_ptr<ITexture> other_texture) override {
        texture_ = other_texture;
    }
    ITexture* GetTexture() const override {
        return texture_.get();
    }
    
    // Рисует фигуру на указанном изображении
    virtual void Draw(Image& image) const override {
        // draw main figure
        Size image_size{image.size() > 0 ? static_cast<int>(image[0].size()) : 0, static_cast<int>(image.size())};
        for (size_t h = position.y ; h < min(size_.height+position.y, image_size.height); ++h)
            for (size_t w = position.x; w < min(size_.width+position.x, image_size.width); ++w)
                image[h][w] = '.';
        // draw texture
        if (texture_){
            const Image& texture_image = texture_->GetImage();
            const Size& texture_size = texture_->GetSize();
            size_t min_height = min(texture_size.height, min(size_.height, image_size.height));
            size_t min_width = min(texture_size.width, min(size_.width, image_size.width));
            for (size_t h = 0; h < min_height; ++h)
                for (size_t w = 0; w < min_width; ++w)
                    image[position.y+h][position.x+w] = texture_image[h % texture_size.height][w % texture_size.width];
        }
    }
private:
    shared_ptr<ITexture> texture_ = MakeTextureSolid({1, 1}, '.');
    Point position;
    Size size_;
};

class Ellipse: public IShape {
public:
    virtual ~Ellipse() = default;
    
    // Возвращает точную копию фигуры.
    // Если фигура содержит текстуру, то созданная копия содержит ту же самую
    // текстуру. Фигура и её копия совместно владеют этой текстурой.
    std::unique_ptr<IShape> Clone() const override {
        return make_unique<Ellipse>(*this);
    }
    
    void SetPosition(Point new_position) override {
        position = new_position;
    }
    Point GetPosition() const override {
        return position;
    }
    
    void SetSize(Size new_size) override {
        size_ = new_size;
    }
    Size GetSize() const override {
        return size_;
    }
    
    void SetTexture(std::shared_ptr<ITexture> other_texture) override {
        texture_ = other_texture;
    }
    ITexture* GetTexture() const override {
        return texture_.get();
    }
    
    // Рисует фигуру на указанном изображении
    virtual void Draw(Image& image) const override {
        // draw main figure
        Size image_size{image.size() > 0 ? static_cast<int>(image[0].size()) : 0, static_cast<int>(image.size())};
        for (size_t h = position.y ; h < min(size_.height+position.y, image_size.height); ++h)
            for (size_t w = position.x; w < min(size_.width+position.x, image_size.width); ++w)
                if (IsPointInEllipse({static_cast<int>(w-position.x), static_cast<int>(h-position.y)}, size_))
                    image[h][w] = '.';
        // draw texture
        if (texture_){
            const Image& texture_image = texture_->GetImage();
            const Size& texture_size = texture_->GetSize();
            size_t min_height = min(texture_size.height, min(size_.height, image_size.height));
            size_t min_width = min(texture_size.width, min(size_.width, image_size.width));
            for (size_t h = 0; h < min_height; ++h)
                for (size_t w = 0; w < min_width; ++w)
                    if (IsPointInEllipse({static_cast<int>(w), static_cast<int>(h)}, size_))
                        image[position.y+h][position.x+w] = texture_image[h % texture_size.height][w % texture_size.width];
        }
    }
private:
    shared_ptr<ITexture> texture_ = MakeTextureSolid({1, 1}, '.');
    Point position;
    Size size_;
};

// Создаёт фигуру заданного типа. Вам нужно реализовать эту функцию.
//std::unique_ptr<IShape> MakeShape(ShapeType shape_type);




// Напишите реализацию функции
unique_ptr<IShape> MakeShape(ShapeType shape_type) {
    switch (shape_type) {
        case ShapeType::Rectangle:
            return make_unique<Rectangle>();
        case ShapeType::Ellipse:
            return make_unique<Ellipse>();
    }
}
