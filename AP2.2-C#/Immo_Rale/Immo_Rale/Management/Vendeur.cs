using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Immo_Rale.DB;
using Immo_Rale.Tools;

namespace Immo_Rale.Management
{
    public class Vendeur
    {
        #region Attributs

        private Guid id = Guid.Empty;
        private string nom;
        private string prenom;
        private string adresse;
        private string ville;
        private string telfixe;
        private string telportable;
        private string email;
        
        #endregion

        #region Properties

        public Guid Id
        {
            get { return id; }
            set { id = value; }
        }
        public string Nom
        {
            get { return nom; }
            set { nom = value; }
        }
        public string Prenom
        {
            get { return prenom; }
            set { prenom = value; }
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
        public string Telfixe
        {
            get { return telfixe; }
            set { telfixe = value; }
        }
        public string Telportable
        {
            get { return telportable; }
            set { telportable = value; }
        }
        public string Email
        {
            get { return email; }
            set { email = value; }
        }
        
        #endregion
        #region Data functions
        private static string TABLE_NAME = "VENDEUR";
        private static string[] COLUMNS = { "ID", "nom", "prenom", "adresse", "ville", "telFixe", "telPortable", "email" };

        private static Vendeur createEntityFrom(Dictionary<string, object> dict)
        {
            Vendeur ob = new Vendeur()
            {
                id = Guid.Parse((String)dict["id"]),
                Nom = (String)dict["nom"],
                Prenom = (String)dict["prenom"],
                Adresse = (String)dict["adresse"],
                Ville = (String)dict["ville"],
                Telfixe = (String)dict["telfixe"],
                Telportable = (String)dict["telportable"],
                Email = (String)dict["email"]
            };

            return ob;
        }

        private String[] getValues()
        {
            return new String[] { "'" + Id.ToString() + "'", "'" + Nom + "'", "'" + Prenom + "'", "'" + Adresse + "'", "'" + Ville + "'"
                , "'" + Telfixe + "'",  "'" + Telportable + "'",  "'" + Email + "'"};
        }

        public static Vendeur getFirst(string where)
        {
            Vendeur res = null;

            var temp = DbManager.getFirst(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                res = createEntityFrom(temp);
            }

            return res;
        }

        public static List<Vendeur> getList(string where)
        {
            List<Vendeur> res = null;

            var temp = DbManager.getList(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                res = new List<Vendeur>();

                foreach (Dictionary<string, object> entry in temp)
                {
                    res.Add(createEntityFrom(entry));
                }
            }

            return res;
        }

        public static Boolean save(Vendeur obj)
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

        public static Boolean insert(Vendeur obj)
        {
            //obj.id = Guid.NewGuid();
            return DbManager.insert(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, obj.getValues());
        }

        public static Boolean update(Vendeur obj)
        {
            return DbManager.update(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, obj.getValues(), TABLE_NAME + ".ID = '" + obj.Id + "'");
        }

        public static Boolean delete(Vendeur obj)
        {
            return DbManager.delete(Configuration.Config.DB_PATH, TABLE_NAME, TABLE_NAME + ".ID = '" + obj.Id + "'");
        }

        #endregion
    }
}
