using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Projet_ImmoRale.Management;
using Projet_ImmoRale.Objets;
using Projet_ImmoRale.FormDesign;

namespace Projet_ImmoRale.Controlleurs
{
    public class AgentControlleur
    {
        public static Boolean save(Agent ag)
        {
            string[] valeurs = ag.getValeurs();

            return Management.DBManager.insert(Management.Configuration.DB_PATH, Management.Configuration.TABLE_AGENT, 
                Management.Configuration.COLONNE_AGENT, valeurs);
        }

        public static Boolean update(Agent ag, string where)
        {
            return Management.DBManager.update(Management.Configuration.DB_PATH, Management.Configuration.TABLE_AGENT,
                Management.Configuration.COLONNE_AGENT, ag.getValeurs(), where);
        }

        public static Boolean delete(string where)
        {
            return Management.DBManager.delete(Management.Configuration.DB_PATH, Management.Configuration.TABLE_AGENT, where);
        }

        public static List<Agent> getList(string where)
        {
            List<Agent> listAgent = new List<Agent>();

            var _list = Management.DBManager.getList(Management.Configuration.DB_PATH, Management.Configuration.TABLE_AGENT, where);

            foreach (Dictionary<string, object> dict in _list)
            {
                listAgent.Add(Objets.Agent.newEntityAgent(dict));
            }

            return listAgent;
        }

        public static Agent getFirst(string where)
        {
            return (Agent.newEntityAgent(Management.DBManager.getFirst(Management.Configuration.DB_PATH, 
                Management.Configuration.TABLE_AGENT, where)));
        }
    }
}
