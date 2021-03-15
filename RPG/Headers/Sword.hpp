#ifndef SWORD_H
#define SWORD_H

namespace HE_Arc::RPG
{
    class Sword
    {
        private:
            int damage;

        public:
            Sword(int _damage);

            int getDamage() const;
    };
}

#endif