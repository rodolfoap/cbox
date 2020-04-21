#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <Eigen/Sparse>
#include <Eigen/Geometry>

namespace Eigen
{
    template <typename T>
    using Vector2 = Eigen::Matrix<T, 2, 1>;

    template <typename T>
    using Rect = Eigen::AlignedBox<T, 2>;

    using FloatRect = Rect<float>;
    using IntRect = Rect<int>;
}

template <typename T>
sf::Vector2<T> eigenToSfVector(const Eigen::Vector2<T>& v)
{
    return { v(0), v(1) };
}

template <typename T>
Eigen::Vector2<T> sfToEigenVector(const sf::Vector2<T>& v)
{
    return { v.x, v.y };
}

template <typename T>
sf::Rect<T> eigenToSfRect(const Eigen::Rect<T>& rect)
{
    return { eigenToSfVector(rect.corner(Eigen::Rect<T>::TopLeft)),
             eigenToSfVector(Eigen::Vector2<T>(rect.sizes())) };
}

struct Entity
{
    Entity(const Eigen::Vector2f& position,
           const Eigen::Vector2f& size,
           sf::Color color) :
        position(position),
        size(size),
        velocity(Eigen::Vector2f::Zero()),
        movementVector(Eigen::Vector2f::Zero()),
        movementSpeed(64.0f),
        shape(eigenToSfVector(size))
    {
        shape.setOrigin(eigenToSfVector(Eigen::Vector2f(size / 2.f)));
        shape.setFillColor(color);
    }

    void handleInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            movementVector(1) = -1.f;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            movementVector(1) = 1.f;
        } else {
            movementVector(1) = 0.f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            movementVector(0) = -1.f;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            movementVector(0) = 1.f;
        } else {
            movementVector(0) = 0.f;
        }
    }

    void setPosition(const Eigen::Vector2f& pos)
    {
        position = pos;
    }

    void update(sf::Time dt)
    {
        velocity = movementVector * movementSpeed;
        move(velocity * dt.asSeconds());
    }

    void move(const Eigen::Vector2f& delta)
    {
        setPosition(position + delta);
    }

    Eigen::FloatRect getWorldRect() const
    {
        Eigen::FloatRect rect(Eigen::Vector2f::Zero(), size);
        return rect.translate(position - size / 2.f);
    }

    void setColor(sf::Color color)
    {
        shape.setFillColor(color);
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const
    {
        states.transform.translate(position(0), position(1));
        target.draw(shape, states);
    }

    bool collidesWith(const Entity& e) const
    {
        return getWorldRect().intersects(e.getWorldRect());
    }

    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
private:
    Eigen::Vector2f position;
    Eigen::Vector2f size;
    Eigen::Vector2f velocity;
    Eigen::Vector2f movementVector;
    float movementSpeed;

    sf::RectangleShape shape;
};



int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");

    Entity player({16.f, 16.f}, {8.f, 8.f}, sf::Color::Green);
    Entity enemy({128.f, 128.f}, {16.f, 16.f}, sf::Color::Red);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.handleInput();

        auto dt = clock.restart();
        player.update(dt);
        enemy.update(dt);

        if(player.collidesWith(enemy)) {
            player.setColor(sf::Color::White);
        } else {
            player.setColor(sf::Color::Green);
        }

        window.clear();
        player.draw(window);
        enemy.draw(window);
        window.display();
    }

    return 0;
}
