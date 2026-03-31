#include <iostream>
#include <vector>
#include <string>
#include <locale>

using namespace std;
class Plat{
private:
    string nom;
    float prix;
public:
    Plat(string n,float p):nom(n),prix(p){}
    Plat():nom(""),prix(0.0){}
    string getnom()const{
      return nom;
    }
    float getprix()const {
      return prix;
    }
    void setnom(string n){
      nom=n;
    }
    void setprix(float p){
      if(p>0)
        prix=p;
      else
        prix=0;
    }
    void afficherPlat(){
       cout<<"le plat "<<nom<<" coute "<<prix<<" £"<<endl;
    }
};
int main()
{
   setlocale(LC_ALL,"");
   Restaurant restaurant;

    // Création et ajout de plats au menu
    Plat plat1("Pizza Margherita", 8.50);
    Plat plat2("Spaghetti Carbonara", 12.00);
    Plat plat3("Tiramisu", 5.50);

    restaurant.getMenu().ajouterPlat(plat1);
    restaurant.getMenu().ajouterPlat(plat2);
    restaurant.getMenu().ajouterPlat(plat3);
    std::cout << "Menu du restaurant :" << std::endl;
    restaurant.getMenu().afficherMenu();
    Commande commande1(1);
    commande1.ajouterPlat(plat1);
    commande1.ajouterPlat(plat3);
    commande1.calculerTotal();
    restaurant.ajouterCommande(commande1);
    std::cout << "\nCommandes enregistrées :" << std::endl;
    restaurant.afficherCommande();
    std::cout << "\nFacture pour la commande 1 :" << std::endl;
    restaurant.genererFacture(1);

    return 0;
}
