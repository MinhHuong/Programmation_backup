using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Immo_Rale.Management;
using Immo_Rale.DB;
using Immo_Rale.Tools;

namespace Immo_Rale.Controlleur
{
    class BiensControlleur
    {
        public Boolean saveBiens_Vendeur(string s_nom, string s_prenom, string s_adresse_pro, string s_email, string s_tel_mobile,
                                        string s_tel_fixe, string s_surfacehabitable, string s_surfaceparcelle, string s_ville_pro,
                                        string s_adresse_bien,string s_quartier, string s_type_habitation, string s_ville_bien, 
                                        string s_prix_souhait,string s_garage, string s_cave, int chambre, int pieces, int bains,
                                        int Eau, string compliment, string date_veut)
        {
            Vendeur obj_vendeur = new Vendeur()
            {   
                Id = Guid.NewGuid(),
                Nom = s_nom,
                Prenom = s_prenom,
                Adresse = s_adresse_pro,
                Ville = s_ville_pro,
                Telfixe = s_tel_fixe,
                Telportable = s_tel_mobile,
                Email = s_email
            };
            Biens obj_biens = new Biens()
            {
                //Id = Guid.NewGuid(),
                Nom_vendeur = s_prenom + " " + s_nom,
                Adresse = s_adresse_bien,
                Ville = s_ville_bien,
                Quartier = s_quartier,
                Statutbien = "DISPONIBLE",
                Surfacehabitable = Aide.parseInt( s_surfacehabitable),
                Surfaceparcelle = Aide.parseInt( s_surfaceparcelle),
                Typehabitation = s_type_habitation,
                Nombre_pieces = pieces,
                Nombre_chambre = chambre,
                Nombre_bains = bains,
                Nombre_eau = Eau,
                Avecgarage = s_garage,
                Aveccavel = s_cave,
                Prixsouhait = Aide.parseFloat(s_prix_souhait),
                Date_miseenvente = date_veut,
                //Prixreel = Aide.parseFloat(dict["prixreel"].ToString()),
                //Date_vente = (String)dict["datevente"],
                //Idacheteur = (String)dict["idacheteur"],
                Idvendeur = obj_vendeur.Id.ToString(),
                Commentaire = compliment
            };
            

            return (Biens.insert(obj_biens) && Vendeur.insert(obj_vendeur));
        }

            public Boolean updateBiens_Vendeur(Biens obj_biens, Vendeur obj_vendeur)
        {
            return Biens.update(obj_biens) && Vendeur.update(obj_vendeur);
        }
        
    }
}
