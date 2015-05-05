using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Immo_Rale.Management;
using Immo_Rale.DB;
using Immo_Rale.Tools;

namespace Immo_Rale.Controlleur
{
    class AgentControlleur
    {
        public Boolean saveAgent(string nom, string prenom,
                                 string tel_fixe, string tel_por_pro, string tel_por_pri,
                                 string email, string agence, string statut)
        {
            Agent ag = new Agent()
            {
                ID = Guid.NewGuid(),
                Fullname = nom + " " + prenom,
                NomAgent = nom,
                PrenomAgent = prenom,
                Telephone_Fixe_Pro = tel_fixe,
                Telephone_Portable_Prive = tel_por_pri,
                Telephone_Portable_Pro = tel_por_pro,
                Email = email,
                Agence_Locale = agence,
                Statut = "ACTIF"
            };

            return Agent.insert(ag);
        }

        public Boolean updateAgent(Agent ag)
        {
            return Agent.update(ag);
        }
    }
}
