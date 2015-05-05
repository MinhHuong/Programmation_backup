using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Immo_Rale.DB;
using Immo_Rale.Tools;

namespace Immo_Rale.Management
{
    public class Souhait
    {
        #region Attributs

        private Guid id = Guid.Empty;
        private string statut;
        private string type;
        private int surface_habitable_min;
        private int surface_parcelle_min;
        private int chambre_min;
        private string cave;
        private string garage;
        private string ville;
        private float prix_max;
        private string id_acheteur;
        private string nom_acheteur;

        #endregion

        #region Properties

        public Guid Id
        {
            get { return id; }
            set { id = value; }
        }
        public string Statut
        {
            get { return statut; }
            set { statut = value; }
        }
        public string Type
        {
            get { return type; }
            set { type = value; }
        }
        public int Surface_habitable_min
        {
            get { return surface_habitable_min; }
            set { surface_habitable_min = value; }
        }
        public int Surface_parcelle_min
        {
            get { return surface_parcelle_min; }
            set { surface_parcelle_min = value; }
        }
        public int Chambre_min
        {
            get { return chambre_min; }
            set { chambre_min = value; }
        }
        public string Cave
        {
            get { return cave; }
            set { cave = value; }
        }
        public string Garage
        {
            get { return garage; }
            set { garage = value; }
        }
        public string Ville
        {
            get { return ville; }
            set { ville = value; }
        }
        public float Prix_max
        {
            get { return prix_max; }
            set { prix_max = value; }
        }
        public string Id_acheteur
        {
            get { return id_acheteur; }
            set { id_acheteur = value; }
        }
        public string Nom_acheteur
        {
            get { return nom_acheteur; }
            set { nom_acheteur = value; }
        }
        #endregion
        #region Data functions
        private static string TABLE_NAME = "SOUHAIT";
        private static string[] COLUMNS = { "ID", "statutS", "typeS", "surfacehabiteMin", "surfaceparcelleMin", "nombrechambreMin", "aveccaveS",
                                              "avecgarageS", "villeS", "prixMax", "idAcheteur", "nomAcheteur" };

        private static Souhait createEntityFrom(Dictionary<string, object> dict)
        {
            Souhait ob = new Souhait()
            {
                Id = Guid.Parse((String)dict["id"]),
                Statut = (String)dict["statuts"],
                Type = (String)dict["types"],
                Surface_habitable_min = Aide.parseInt(dict["surfacehabitemin"].ToString()),
                Surface_parcelle_min =Aide.parseInt(dict["surfaceparcellemin"].ToString()),
                Chambre_min = Aide.parseInt(dict["nombrechambremin"].ToString()),
                Cave = (String)dict["aveccaves"],
                Garage = (String)dict["avecgarages"],
                Ville = (String)dict["villes"],
                Prix_max = Aide.parseFloat(dict["prixmax"].ToString()),
                Id_acheteur = (String)dict["idacheteur"],
                Nom_acheteur = (String)dict["nomacheteur"]
            };

            return ob;
        }

        private String[] getValues()
        {
            return new String[] { "'" + Id.ToString() + "'", "'" + Statut + "'", "'" + Type + "'",Surface_habitable_min.ToString(),
                                    Surface_parcelle_min.ToString(), Chambre_min.ToString(),"'" + Cave + "'"
                                    , "'" + Garage + "'",  "'" + Ville + "'", Prix_max.ToString(), "'" + Id_acheteur + "'", "'" + Nom_acheteur + "'"};
        }

        public static Souhait getFirst(string where)
        {
            Souhait res = null;

            var temp = DbManager.getFirst(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                res = createEntityFrom(temp);
            }

            return res;
        }

        public static List<Souhait> getList(string where)
        {
            List<Souhait> res = null;

            var temp = DbManager.getList(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                res = new List<Souhait>();

                foreach (Dictionary<string, object> entry in temp)
                {
                    res.Add(createEntityFrom(entry));
                }
            }

            return res;
        }

        public static Boolean save(Souhait obj)
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

        public static Boolean insert(Souhait obj)
        {
            //obj.id = Guid.NewGuid();
            return DbManager.insert(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, obj.getValues());
        }

        public static Boolean update(Souhait obj)
        {
            return DbManager.update(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, obj.getValues(), TABLE_NAME + ".ID = '" + obj.Id + "'");
        }

        public static Boolean delete(Souhait obj)
        {
            return DbManager.delete(Configuration.Config.DB_PATH, TABLE_NAME, TABLE_NAME + ".ID = '" + obj.Id + "'");
        }

        #endregion
    }
}
