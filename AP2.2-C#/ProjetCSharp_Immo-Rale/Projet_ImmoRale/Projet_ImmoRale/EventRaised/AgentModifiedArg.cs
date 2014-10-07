using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Projet_ImmoRale.Objets;
using Projet_ImmoRale.FormDesign;

namespace Projet_ImmoRale.EventRaised
{
    public class AgentModifiedArg
    {
        private Agent ag;

        public Agent Agent
        {
            get { return ag; }
        }

        public AgentModifiedArg(Agent agent)
        {
            ag = agent;
        }
    }
}
