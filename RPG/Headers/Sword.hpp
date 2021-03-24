#ifndef SWORD_H
#define SWORD_H

namespace HE_Arc::RPG
{
    class Sword
    {
    private:
        // Atributes
        int damage;

    public:
        // Constructors and Destructor
        Sword();
        Sword(int _damage);
        Sword(const Sword &);

        // Methods int
        int getDamage() const { return this->damage; }
    };
}

#endif