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
class Menu{
private:
    vector <Plat> plats;
public:
    void ajouterPlat(Plat p){
       plats.push_back(p);
    }
    void afficherMenu(){
       for(int i=0;i<plats.size();i++){
          plats[i].afficherPlat();
       }
    }
    Plat chercherPlat(string nom){
        bool trouve(false);
        for(const auto& p:plats){//cette ligne va permettre de balayer automatiquement les valeurs du tableau , grace a "auto" il prendra directement le type approprier il prendra donc valeur par valeur tous les elements du tableau
            if(p.getnom()==nom){
                trouve=true;
                return p;
            }
            if(!trouve)
                cout<<"le plat "<<nom<<" n'existe pas dans le menu"<<endl;

        }
    }

};
class Commande{
private:
    int idCommande;
    vector <Plat> platscommandes;
    float total;
public:
    Commande(int i):idCommande(i){}
    Commande():idCommande(0),total(0.O){}
    void ajouterPlat(Plat p){
       platscommandes.push_back(p);
    }
    int getidCommande(){
       return idCommande;
    }
    void calculerTotal(){
       total=0;
       for(int i=0;i<platscommandes.size();i++){
            total=total+platscommandes[i].getprix();
       }
    }
    void afficherCommande(){
       cout<<"la commande a pour identifiant: "<<idCommande<<endl;
       cout<<"elle comprends les plats suivants:"<<endl;
       for(int i=0;i<platscommandes.size();i++){
            cout<<"-";
            platscommandes[i].afficherPlat();
       }
       cout<<"pour un Total de:"<<total<<" £"<<endl;
    }
};
class Restaurant{
private:
    Menu menu;//menu du restaurant
    vector <Commande> commandes;//commande des clients
public:
    void ajouterCommande (Commande c){
        commandes.push_back(c);
    }
    void afficherCommande(){
        for(int i=0;i<commandes.size();i++){
            cout<<"-commande "<<i+1<<":";
            commandes[i].afficherCommande();
        }
    }
    void genererFacture(int id){
       for(int i=0;i<commandes.size();i++){
           if(commandes[i].getidCommande()==id)
              cout<<"facture: "<<endl;
              commandes[i].afficherCommande();
       }
    }
    Menu& getMenu(){
     return menu;
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
