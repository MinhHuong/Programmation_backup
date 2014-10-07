using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Projet_ImmoRale.EventRaised;
using Projet_ImmoRale.FormDesign;
using Projet_ImmoRale.Management;
using Projet_ImmoRale.Objets;
using Projet_ImmoRale.Tools;

namespace Projet_ImmoRale
{
    public partial class MainPage : Form
    {
        private bool modified = false;
        #region Initialiser
        public MainPage()
        {
            InitializeComponent();
            Init();
        }

        public void Init()
        {
            tsb_saveFiche.Enabled = false;
            tsb_deleteFiche.Enabled = false;
            ficheBien.Visible = false;
            listeBiens.Visible = false;

            tsb_saveAgent.Enabled = false;
            tsb_deleteFicheAgent.Enabled = false;
            ficheAgent.Visible = false;
            listeAgents.Visible = false;
        }

        private void llb_quit_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Application.Exit();
        }

        private void tsb_nouveauFiche_Click(object sender, EventArgs e)
        {
            ficheBien.Visible = true;
            tsb_saveFiche.Enabled = true;
            tsb_deleteFiche.Enabled = true;
            listeBiens.Visible = false;
        }

        private void tsb_findBien_Click(object sender, EventArgs e)
        {
            listeBiens.Visible = true;
            tsb_saveFiche.Enabled = false;
            tsb_deleteFiche.Enabled = false;
            ficheBien.Visible = false;
        }

        private void tsb_newAgent_Click(object sender, EventArgs e)
        {
            ficheAgent.effacerTout();
            ficheAgent.Visible = true;
            tsb_saveAgent.Enabled = true;
            modified = false;
            tsb_deleteFicheAgent.Enabled = true;
            listeAgents.Visible = false;
        }

        private void tsb_findAgent_Click(object sender, EventArgs e)
        {
            ficheAgent.Visible = false;
            tsb_saveAgent.Enabled = false;
            tsb_deleteFicheAgent.Enabled = false;
            listeAgents.Visible = true;
        }
        #endregion

        private void tsb_saveAgent_Click(object sender, EventArgs e)
        {
            if (ficheAgent.verifier())
            {
                if (modified)
                {
                    ficheAgent.updateAgent();
                }
                else
                {
                    ficheAgent.saveAgent();
                }
            }
            else
            {
                MessageBox.Show("Fiche agent non valide");
            }
        }

        private void tsb_deleteFicheAgent_Click(object sender, EventArgs e)
        {
            ficheAgent.effacerTout();
        }

        private void AgentModified_MainPage(object sender, AgentModifiedArg e)
        {
            listeAgents.Visible = false;
            ficheAgent.Visible = true;
            tsb_saveAgent.Enabled = true;
            tsb_deleteFicheAgent.Enabled = true;
            ficheAgent.bindingData(e.Agent);
            modified = true;
        }

        
    }
}
