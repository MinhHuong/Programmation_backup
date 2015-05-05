using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Immo_Rale.DB;
using Immo_Rale.Tools;

namespace Immo_Rale.Management
{
    public class Agent
    {

#region attributs

        private Guid id = Guid.Empty;
        private string prenom;
        private string nom;
        private string tel_fixe_pro;
        private string tel_portable_pro;
        private string tel_portable_prive;
        private string email;
        private string agence_locale;
        private string statut;
        private string fullname;

#endregion

#region proprietes

        public Guid ID
        {
            get { return id; }
            set { id = value; }
        }

        public string PrenomAgent
        {
            get { return prenom; }
            set { prenom = value; }
        }

        public string NomAgent
        {
            get { return nom; }
            set { nom = value; }
        }

        public string Telephone_Fixe_Pro
        {
            get { return tel_fixe_pro; }
            set { tel_fixe_pro = value; }
        }

        public string Telephone_Portable_Pro
        {
            get { return tel_portable_pro; }
            set { tel_portable_pro = value; }
        }

        public string Telephone_Portable_Prive
        {
            get { return tel_portable_prive; }
            set { tel_portable_prive = value; }
        }

        public string Email
        {
            get { return email; }
            set { email = value; }
        }

        public string Agence_Locale
        {
            get { return agence_locale; }
            set { agence_locale = value; }
        }

        public string Statut
        {
            get { return statut; }
            set { statut = value; }
        }

        public string Fullname
        {
            get { return fullname; }
            set { fullname = value; }
        }

#endregion

#region Methodes

        private static string TABLE_NAME = "AGENT";
        private static string[] COLUMNS = { "ID", "FullName", "Prenom", "Nom", "TelFixePro", "TelPortablePro", 
                                             "TelPortablePrive", "Email", "AgenceLocale", "Statut" };

        private static Agent createEntityFrom(Dictionary<string, object> dict)
        {
            Agent ag = new Agent()
            {
                ID = Guid.Parse((String)dict["id"]),
                Fullname = (String)dict["fullname"],
                PrenomAgent = (String)dict["prenom"],
                NomAgent = (String)dict["nom"],
                Telephone_Fixe_Pro = (String)dict["telfixepro"],
                Telephone_Portable_Pro = (String)dict["telportablepro"],
                Telephone_Portable_Prive = (String)dict["telportableprive"],
                Email = (String)dict["email"],
                Agence_Locale = (String)dict["agencelocale"],
                Statut = (String)dict["statut"]
            };

            return ag;
        }

        private String[] getValues()
        {
            return new String[] { "'" + ID.ToString() + "'", 
                                  "'" + Fullname + "'",
                                  "'" + PrenomAgent + "'",
                                  "'" + NomAgent + "'",
                                  "'" + Telephone_Fixe_Pro + "'",
                                  "'" + Telephone_Portable_Pro + "'",
                                  "'" + Telephone_Portable_Prive + "'",
                                  "'" + Email + "'",
                                  "'" + Agence_Locale + "'",
                                  "'" + Statut + "'"};
        }

        public static Agent getFirst(string where)
        {
            Agent ag = null;

            var temp = DbManager.getFirst(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                ag = createEntityFrom(temp);
            }

            return ag;
        }

        public static List<Agent> getList(string where)
        {
            List<Agent> la = null;

            var temp = DbManager.getList(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                la = new List<Agent>();

                foreach (Dictionary<string, object> t in temp)
                {
                    la.Add(createEntityFrom(t));
                }
            }

            return la;
        }

        public static Boolean insert(Agent ag)
        {
            //ag.ID = new Guid();
            return DbManager.insert(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, ag.getValues());
        }

        public static Boolean update(Agent ag)
        {
            return DbManager.update(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, ag.getValues(), TABLE_NAME + ".ID = '" + ag.ID + "'");
        }

        public static Boolean save(Agent ag)
        {
            if (ag.ID != null)
            {
                return update(ag);
            }
            else
            {
                return insert(ag);
            }
        }

        public static Boolean delete(Agent ag)
        {
            return DbManager.delete(Configuration.Config.DB_PATH, TABLE_NAME, TABLE_NAME + ".ID = " + ag.ID + "'");
        }

#endregion

    }
}
