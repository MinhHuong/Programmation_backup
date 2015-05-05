using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Immo_Rale.Configuration
{
    public class Config
    {
        public static string DB_PATH = ".\\Database\\Rale_database.db";
        public static String[] VILLE_ROLE = { "TP HCM", "Can Tho", "Ha Noi", "Nha Trang", "Hue", "Da Nang", "Bien Hoa", "Binh Duong", "Long An", "My Tho", "Bac Lieu", "Ca Mau" };
        public static String[] HABITATION_ROLE = { "Maison", "Appartement" };
        public static String[] STATUT_BIEN_ROLE = { "DISPONIBLE", "SOUS SEING", "VENDU", "RETIRE" };

        public static String[] STATUT_SOUHAIT_ROLE = { "EN COURS", "OBSOLETE" };

        public static String[] AGENCE_LOCALE_CHERCHE = { "TOUT", "Bordeaux", "Talence", "Cenon", "Mérignac" };
        public static String[] STATUT_AGENT_CHERCHE = { "TOUT", "ACTIF", "ANCIEN EMPLOYE" };

        public static String[] AGENCE_LOCALE = { "Bordeaux", "Talence", "Cenon", "Mérignac" };
        public static String[] STATUT_AGENT = { "ACTIF", "ANCIEN EMPLOYE" };
    }
}

