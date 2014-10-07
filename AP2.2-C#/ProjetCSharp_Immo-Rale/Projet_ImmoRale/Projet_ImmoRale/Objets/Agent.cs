using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Projet_ImmoRale.Management;
using Projet_ImmoRale.Tools;

namespace Projet_ImmoRale.Objets
{
    public class Agent
    {
        #region attributs
        private Guid idAgent;
        private string nomAgent;
        private string telFixePro;
        private string telPorPro;
        private string telPorPri;
        private string emailAgent;
        private string agenceAgent;
        private string statutAgent;
        private string photoAgent;
        #endregion

        #region propriétés
        public Guid IDAgent
        {
            get { return idAgent; }
            set { idAgent = value; }
        }

        public string NomAgent
        {
            get { return nomAgent; }
            set { nomAgent = value; }
        }

        public string TelFixePro
        {
            get { return telFixePro; }
            set { telFixePro = value; }
        }

        public string TelPortablePro
        {
            get { return telPorPro; }
            set { telPorPro = value; }
        }

        public string TelPortablePrive
        {
            get { return telPorPri; }
            set { telPorPri = value; }
        }

        public string EmailAgent
        {
            get { return emailAgent; }
            set { emailAgent = value; }
        }

        public string AgenceLocale
        {
            get { return agenceAgent; }
            set { agenceAgent = value; }
        }

        public string StatutAgent
        {
            get { return statutAgent; }
            set { statutAgent = value; }
        }

        public string PhotoAgent
        {
            get { return photoAgent; }
            set { photoAgent = value; }
        }
        #endregion

        public Agent(string nom, string telFP, string telPPro, string telPPri, string email, string agence, string stt, string picAg)
        {
            idAgent = Guid.NewGuid(); 
            nomAgent = nom;
            telFixePro = telFP;
            telPorPro = telPPro;
            telPorPri = telPPri;
            emailAgent = email;
            agenceAgent = agence;
            statutAgent = stt;
            photoAgent = picAg;
        }

        public Agent()
        {
            idAgent = Guid.Empty;
            nomAgent = telFixePro = telPorPro = telPorPri = emailAgent = agenceAgent = statutAgent = "";
            photoAgent = null;
        }

        public static Agent newEntityAgent(Dictionary<string, object> dict)
        {
            Agent ag = new Agent();

            ag.IDAgent = Guid.Parse((string)dict["id"]);
            ag.NomAgent = (string)dict["fullname"];
            ag.TelFixePro = (string)dict["telfixepro"];
            ag.TelPortablePro = (string)dict["telportablepro"];
            ag.TelPortablePrive = (string)dict["telportableprive"];
            ag.EmailAgent = (string)dict["email"];
            ag.AgenceLocale = (string)dict["agencelocale"];
            ag.StatutAgent = (string)dict["statut"];

            try
            {
                ag.PhotoAgent = (string)dict["photoagent"];
            }
            catch
            { }

            return ag;
        }

        public string[] getValeurs()
        {
            return new string[] { "'" + idAgent.ToString() + "'",
                                  "'" + nomAgent + "'",
                                  "'" + telFixePro + "'",
                                  "'" + telPorPro + "'",
                                  "'" + telPorPri + "'",
                                  "'" + emailAgent + "'",
                                  "'" + agenceAgent + "'",
                                  "'" + statutAgent + "'",
                                  "'" + photoAgent + "'"};
        }


    }
}
