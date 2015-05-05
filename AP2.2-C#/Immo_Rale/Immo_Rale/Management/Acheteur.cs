using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Immo_Rale.DB;
using Immo_Rale.Tools;

namespace Immo_Rale.Management
{
    public class Acheteur
    {
        #region Attributs

        private Guid id = Guid.Empty;
        private string nom;
        private string prenom;
        private string adresse;
        private string telfixe;
        private string telportable;
        private string email;
        private string idagent;

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
        public string Idagent
        {
            get { return idagent; }
            set { idagent = value; }
        }

        #endregion
        #region Data functions
        private static string TABLE_NAME = "ACHETEUR";
        private static string[] COLUMNS = { "ID", "nomAcheteur", "prenomAcheteur", "adresseAcheteur", "telfixeAcheteur", "telmobileAcheteur", "emailAcheteur", "idAgent" };

        private static Acheteur createEntityFrom(Dictionary<string, object> dict)
        {
            Acheteur ob = new Acheteur()
            {
                id = Guid.Parse((String)dict["id"]),
                Nom = (String)dict["nomacheteur"],
                Prenom = (String)dict["prenomacheteur"],
                Adresse = (String)dict["adresseacheteur"],
                Telfixe = (String)dict["telfixeacheteur"],
                Telportable = (String)dict["telmobileacheteur"],
                Email = (String)dict["emailacheteur"],
                Idagent = (String)dict["idagent"]
            };

            return ob;
        }

        private String[] getValues()
        {
            return new String[] { "'" + Id.ToString() + "'", "'" + Nom + "'", "'" + Prenom + "'", "'" + Adresse + "'"
                                    , "'" + Telfixe + "'",  "'" + Telportable + "'",  "'" + Email + "'",  "'" + Idagent + "'"};
        }

        public static Acheteur getFirst(string where)
        {
            Acheteur res = null;

            var temp = DbManager.getFirst(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                res = createEntityFrom(temp);
            }

            return res;
        }

        public static List<Acheteur> getList(string where)
        {
            List<Acheteur> res = null;

            var temp = DbManager.getList(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                res = new List<Acheteur>();

                foreach (Dictionary<string, object> entry in temp)
                {
                    res.Add(createEntityFrom(entry));
                }
            }

            return res;
        }

        public static Boolean save(Acheteur obj)
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

        public static Boolean insert(Acheteur obj)
        {
            //obj.id = Guid.NewGuid();
            return DbManager.insert(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, obj.getValues());
        }

        public static Boolean update(Acheteur obj)
        {
            return DbManager.update(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, obj.getValues(), TABLE_NAME + ".ID = '" + obj.Id + "'");
        }

        public static Boolean delete(Acheteur obj)
        {
            return DbManager.delete(Configuration.Config.DB_PATH, TABLE_NAME, TABLE_NAME + ".ID = '" + obj.Id + "'");
        }

        #endregion
    }
}
