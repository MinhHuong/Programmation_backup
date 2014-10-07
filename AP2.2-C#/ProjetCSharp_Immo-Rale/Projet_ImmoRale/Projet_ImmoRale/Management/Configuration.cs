using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projet_ImmoRale.Management
{
    public class Configuration
    {
        public static string DB_PATH = "..\\..\\..\\Database\\Immo-Rale-DB.db";

        #region BIEN
        public static string[] TYPE_HABITATION = { "Maison", "Appartement" };
        public static string[] STATUT_BIEN = { "Disponible", "Sous seing", "Vendu", "Retiré" };
        #endregion

        #region AGENT
        public static string[] AGENCE_LOCALE = { "Tout", "Bordeaux", "Talence", "Cenon", "Mérignac" };
        public static string[] STATUT_AGENT = { "Disponible", "Ancien employé" };
        public static string TABLE_AGENT = "AGENT";
        public static string[] COLONNE_AGENT = { "ID", "FullName", "TelFixePro", "TelPortablePro", "TelPortablePrive", "Email", "AgenceLocale", "Statut", "PhotoAgent" };
        #endregion
    }
}
