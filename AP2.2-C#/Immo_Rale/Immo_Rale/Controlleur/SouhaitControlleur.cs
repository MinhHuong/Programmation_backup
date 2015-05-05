using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Immo_Rale.DB;
using Immo_Rale.Tools;
using Immo_Rale.Management;

namespace Immo_Rale.Controlleur
{
    class SouhaitControlleur
    {
        public Boolean saveSouhait_Acheteur(string s_nom, string s_prenom, string s_adresse, string s_email, string s_tel_mobile, string s_tel_fixe, string s_habitablemin,
                                    string s_parcellemin, string s_villesouhait, string s_type,
                                    string s_statut, string s_garage, string s_cave, int chambre,
                                    string prix, Management.Agent agent)
            
        {
            Acheteur obj_Acheteur = new Acheteur()
            {
                Id = Guid.NewGuid(),
                Nom = s_nom,
                Prenom = s_prenom,
                Adresse = s_adresse,                
                Telfixe = s_tel_fixe,
                Telportable = s_tel_mobile,
                Email = s_email,
                Idagent = agent.ID.ToString()
            };
            Souhait obj_Souhait = new Souhait()
            {
                Id = Guid.NewGuid(),
                Statut = s_statut,
                Type = s_type,
                Surface_habitable_min =  Aide.parseInt(s_habitablemin),
                Surface_parcelle_min =Aide.parseInt(s_parcellemin),
                Chambre_min = Aide.parseInt(s_parcellemin),
                Cave = s_cave,
                Garage = s_garage,
                Ville = s_villesouhait,
                Prix_max = Aide.parseFloat(prix),
                Id_acheteur = obj_Acheteur.Id.ToString(),
                Nom_acheteur = obj_Acheteur.Prenom + " " + obj_Acheteur.Nom,
            };


            return (Souhait.insert(obj_Souhait) && Acheteur.insert(obj_Acheteur));
        }

        public Boolean newSouhait_oldAcheteur(Acheteur obj_Acheteur, string s_habitablemin,
                                   string s_parcellemin, string s_villesouhait, string s_type,
                                   string s_statut, string s_garage, string s_cave, int chambre,
                                   string prix)
        {
            Souhait obj_Souhait = new Souhait()
            {
                Id = Guid.NewGuid(),
                Statut = s_statut,
                Type = s_type,
                Surface_habitable_min = Aide.parseInt(s_habitablemin),
                Surface_parcelle_min = Aide.parseInt(s_parcellemin),
                Chambre_min = Aide.parseInt(s_parcellemin),
                Cave = s_cave,
                Garage = s_garage,
                Ville = s_villesouhait,
                Prix_max = Aide.parseFloat(prix),
                Id_acheteur = obj_Acheteur.Id.ToString(),
                Nom_acheteur = obj_Acheteur.Prenom + " " + obj_Acheteur.Nom,
            };
            return (Souhait.insert(obj_Souhait) && Acheteur.update(obj_Acheteur));
        }

        public Boolean updateSouhait_Acheteur(Souhait obj_Souhait, Acheteur obj_Acheteur)
        {
            return (Souhait.update(obj_Souhait) && Acheteur.update(obj_Acheteur));
        }
    }
}
