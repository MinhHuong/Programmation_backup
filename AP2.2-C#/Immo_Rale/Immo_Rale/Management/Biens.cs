using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Immo_Rale.DB;
using Immo_Rale.Tools;

namespace Immo_Rale.Management
{
    public class Biens
    {
        #region Attributs

        private Guid id = Guid.Empty;
        private string nom_vendeur;
        private string adresse;
        private string ville;
        private string statutbien;
        private string quartier;
        private int surfacehabitable;
        private int surfaceparcelle;
        private string typehabitation;
        private int nombre_pieces;
        private int nombre_chambre;
        private int nombre_bains;
        private int nombre_eau;
        private string avecgarage;
        private string aveccavel;
        private float prixsouhait;
        private string date_miseenvente;
        private float prixreel;
        private string date_vente;
        private string idacheteur;
        private string idvendeur;
        private string commentaire;

        #endregion

        #region Properties

        public Guid Id
        {
            get { return id; }
            set { id = value; }
        }
        public string Nom_vendeur
        {
            get { return nom_vendeur; }
            set { nom_vendeur = value; }
        }
        public string Adresse
        {
            get { return adresse; }
            set { adresse = value; }
        }
        public string Ville
        {
            get { return ville; }
            set { ville = value; }
        }
        public string Statutbien
        {
            get { return statutbien; }
            set { statutbien = value; }
        }
        public string Quartier
        {
            get { return quartier; }
            set { quartier = value; }
        }
        public int Surfacehabitable
        {
            get { return surfacehabitable; }
            set { surfacehabitable = value; }
        }
        public int Surfaceparcelle
        {
            get { return surfaceparcelle; }
            set { surfaceparcelle = value; }
        }
        public string Typehabitation
        {
            get { return typehabitation; }
            set { typehabitation = value; }
        }
        public int Nombre_pieces
        {
            get { return nombre_pieces; }
            set { nombre_pieces = value; }
        }
        public int Nombre_chambre
        {
            get { return nombre_chambre; }
            set { nombre_chambre = value; }
        }
        public int Nombre_bains
        {
            get { return nombre_bains; }
            set { nombre_bains = value; }
        }
        public int Nombre_eau
        {
            get { return nombre_eau; }
            set { nombre_eau = value; }
        }
        public string Avecgarage
        {
            get { return avecgarage; }
            set { avecgarage = value; }
        }
        public string Aveccavel
        {
            get { return aveccavel; }
            set { aveccavel = value; }
        }
        public float Prixsouhait
        {
            get { return prixsouhait; }
            set { prixsouhait = value; }
        }
        public string Date_miseenvente
        {
            get { return date_miseenvente; }
            set { date_miseenvente = value; }
        }
        public float Prixreel
        {
            get { return prixreel; }
            set { prixreel = value; }
        }
        public string Date_vente
        {
            get { return date_vente; }
            set { date_vente = value; }
        }
        public string Idacheteur
        {
            get { return idacheteur; }
            set { idacheteur = value; }
        }
        public string Idvendeur
        {
            get { return idvendeur; }
            set { idvendeur = value; }
        }
        public string Commentaire
        {
            get { return commentaire; }
            set { commentaire = value; }
        }


        #endregion

        #region Data functions
        private static string TABLE_NAME = "BIENS";
        private static string[] COLUMNS = { "ID", "Nom_Vendeur", "adresse", "ville", "quartier", "statutBien",
                                              "surfaceHabitable", "surfaceParcelle", "typeHabitation", "nombrePieces", 
                                              "nombreChambres", "nombreBains", "nombreEau", "avecGarage","avecCave", "prixSouhait",
                                              "dateMiseEnVente", "prixReel", "dateVente", "idAcheteur", "idVendeur", "commentaire" };

        private static Biens createEntityFrom(Dictionary<string, object> dict)
        {
            Biens ob = new Biens()
            {
                id = Guid.Parse((String)dict["id"]),
                Nom_vendeur = (String)dict["nom_vendeur"],
                Adresse = (String)dict["adresse"],
                Ville = (String)dict["ville"],
                Quartier = (String)dict["quartier"],
                Statutbien = (String)dict["statutbien"],                
                Surfacehabitable = Aide.parseInt(dict["surfacehabitable"].ToString()),
                Surfaceparcelle = Aide.parseInt(dict["surfaceparcelle"].ToString()),
                Typehabitation = (String)dict["typehabitation"],
                Nombre_pieces = Aide.parseInt(dict["nombrepieces"].ToString()),
                Nombre_chambre = Aide.parseInt(dict["nombrechambres"].ToString()),
                Nombre_bains = Aide.parseInt(dict["nombrebains"].ToString()),
                Nombre_eau = Aide.parseInt(dict["nombreeau"].ToString()),
                Avecgarage = (String)dict["avecgarage"],
                Aveccavel = (String)dict["aveccave"],
                Prixsouhait = Aide.parseFloat(dict["prixsouhait"].ToString()),
                Date_miseenvente = (String)dict["datemiseenvente"],
                Prixreel = Aide.parseFloat(dict["prixreel"].ToString()),
                Date_vente = (String)dict["datevente"],
                Idacheteur = (String)dict["idacheteur"],
                Idvendeur = (String)dict["idvendeur"],
                Commentaire = (String)dict["commentaire"]
            };

            return ob;
        }

        private String[] getValues()
        {
            return new String[] { "'" + Id.ToString() + "'", "'" + Nom_vendeur + "'", "'" + Adresse + "'", "'" + Ville + "'", "'" + Quartier + "'"
                , "'" + Statutbien + "'", Surfacehabitable.ToString(), Surfaceparcelle.ToString(), "'" + Typehabitation + "'", Nombre_pieces .ToString()
            , Nombre_chambre.ToString(), Nombre_bains.ToString(), Nombre_eau.ToString(), "'" + Avecgarage + "'", "'" + Aveccavel + "'" 
            , Prixsouhait.ToString(),  "'" + Date_miseenvente + "'",Prixreel.ToString(), "'" + Date_vente + "'", "'" + Idacheteur + "'" , "'" + Idvendeur + "'", "'" + Commentaire + "'"};
        }

        public static Biens getFirst(string where)
        {
            Biens res = null;

            var temp = DbManager.getFirst(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                res = createEntityFrom(temp);
            }

            return res;
        }

        public static List<Biens> getList(string where)
        {
            List<Biens> res = null;

            var temp = DbManager.getList(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                res = new List<Biens>();

                foreach (Dictionary<string, object> entry in temp)
                {
                    res.Add(createEntityFrom(entry));
                }
            }
            return res;
        }

        public static Boolean save(Biens obj)
        {
            if (obj.Id == Guid.Empty)
            {
                return insert(obj);
            }
            else
            {
                return update(obj);
            }
        }

        public static Boolean insert(Biens obj)
        {
            obj.id = Guid.NewGuid();
            return DbManager.insert(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, obj.getValues());
        }

        public static Boolean update(Biens obj)
        {
            return DbManager.update(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, obj.getValues(), TABLE_NAME + ".ID = '" + obj.Id + "'");
        }

        public static Boolean delete(Biens obj)
        {
            return DbManager.delete(Configuration.Config.DB_PATH, TABLE_NAME, TABLE_NAME + ".ID = '" + obj.Id + "'");
        }

        #endregion
    }
}
