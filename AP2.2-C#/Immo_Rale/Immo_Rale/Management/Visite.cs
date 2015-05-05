using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Immo_Rale.DB;

namespace Immo_Rale.Management
{
    public class Visite
    {
        #region Attributs

        private Guid id = Guid.Empty;
        private Guid id_agent;
        private Guid id_acheteur;
        private Guid id_biens;
        private string date;

        #endregion

        #region Properties

        public Guid Id
        {
            get { return id; }
            set { id = value; }
        }
        public Guid Id_agent
        {
            get { return id_agent; }
            set { id_agent = value; }
        }
        public Guid Id_acheteur
        {
            get { return id_acheteur; }
            set { id_acheteur = value; }
        }
        public Guid Id_biens
        {
            get { return id_biens; }
            set { id_biens = value; }
        }
        public string Date
        {
            get { return date; }
            set { date = value; }
        }
        #endregion
        #region Data functions
        private static string TABLE_NAME = "VISITE";
        private static string[] COLUMNS = { "ID", "idAgent", "idAcheteur", "idBiens", "date" };

        private static Visite createEntityFrom(Dictionary<string, object> dict)
        {
            Visite ob = new Visite()
            {
                Id = Guid.Parse((String)dict["id"]),
                Id_agent = Guid.Parse((String)dict["idagent"]),
                Id_acheteur = Guid.Parse((String)dict["idacheteur"]),
                Id_biens = Guid.Parse((String)dict["idbiens"]),
                Date = (String)dict["date"]
            };


            
            
            return ob;
        }

        private String[] getValues()
        {
            return new String[] { "'" + Id.ToString() + "'", "'" + Id_agent.ToString() + "'", "'" + Id_acheteur.ToString() + "'", "'" + Id_biens.ToString() + "'", "'" + Date + "'"};
        }

        public static Visite getFirst(string where)
        {
            Visite res = null;

            var temp = DbManager.getFirst(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                res = createEntityFrom(temp);
            }

            return res;
        }
        public static List<Visite> getList(string where)
        {
            List<Visite> res = null;

            var temp = DbManager.getList(Configuration.Config.DB_PATH, TABLE_NAME, where);
            if (temp != null)
            {
                res = new List<Visite>();

                foreach (Dictionary<string, object> entry in temp)
                {
                    res.Add(createEntityFrom(entry));
                }
            }

            return res;
        }

        //public static Boolean save(Visite obj)
        //{
        //    if (obj.Id == Guid.Empty)
        //    {
        //        return insert(obj);
        //    }
        //    else
        //    {
        //        return update(obj);
        //    }
        //}

        public static Boolean insert(Visite obj)
        {
            obj.id = Guid.NewGuid();
            return DbManager.insert(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, obj.getValues());
        }

        //public static Boolean update(Visite obj)
        //{
        //    return DbManager.update(Configuration.Config.DB_PATH, TABLE_NAME, COLUMNS, obj.getValues(), TABLE_NAME + ".ID = '" + obj.Id + "'");
        //}

        //public static Boolean delete(Visite obj)
        //{
        //    return DbManager.delete(Configuration.Config.DB_PATH, TABLE_NAME, TABLE_NAME + ".ID = '" + obj.Id + "'");
        //}

        #endregion
    }
}
