#include "Character.cpp"
#include "Weapon.cpp"

int main()
{
    cout << "Le village s'endort..." << endl;
    /*Weapon nailClipper("nail clipper", 45);
    Weapon spikedMass("spiked mass", 15);*/
    Character geralt("Geralt", 100, 100, "nail Clipper", 75);
    Character yennefer("Yennefer", 100, 100, "spiked Mass", 15);
    geralt.display();
    geralt.attack(yennefer);
    yennefer.display();
    yennefer.takeLifePotion(25);
    yennefer.display();
    yennefer.switchWeapon("stapler", 60);
    yennefer.display();
    yennefer.attack(geralt);
    geralt.display();
    geralt.attack(yennefer);
    yennefer.display();
    return 0;
}