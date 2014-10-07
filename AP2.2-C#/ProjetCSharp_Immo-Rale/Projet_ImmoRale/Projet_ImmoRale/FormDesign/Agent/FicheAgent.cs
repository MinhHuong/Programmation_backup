using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Projet_ImmoRale.Management;
using Projet_ImmoRale.Objets;
using Projet_ImmoRale.Tools;
using Projet_ImmoRale.Controlleurs;

namespace Projet_ImmoRale.FormDesign
{
    public partial class FicheAgent : UserControl
    {
        private Agent agent = null;
        private bool estValide;
        private string pathImage = "";

        public bool Valide
        {
            get { return estValide; }
            set { estValide = value; }
        }

        public bool verifier()
        {
            return (tb_fullnameAgent.Text != "" && tb_porPro.Text != "" && tb_mail.Text != "");
        }

        public void effacerTout()
        {
            tb_fullnameAgent.Text = tb_telFP.Text = tb_porPro.Text = tb_porPri.Text = tb_mail.Text = "";
            picBox_agent.Image = picBox_agent.InitialImage;
            cbb_agenceLocale.SelectedIndex = cbb_stt.SelectedIndex = 0;
        }

        public string PathImage
        {
            get { return pathImage; }
            set { pathImage = value; }
        }

        public FicheAgent()
        {
            InitializeComponent();
            loadCombobox();
        }

        private void loadCombobox()
        {
            cbb_stt.Items.Clear();

            foreach(string it in Management.Configuration.AGENCE_LOCALE)
            {
                if (it != "Tout")
                {
                    cbb_agenceLocale.Items.Add(it);
                }
            }
            cbb_agenceLocale.SelectedIndex = 0;

            cbb_stt.Items.Add(Management.Configuration.STATUT_AGENT[0]);
            cbb_stt.SelectedIndex = 0;
        }

        private void loadComboBoxModified()
        {
            cbb_stt.Items.Clear();

            foreach (string label in Management.Configuration.STATUT_AGENT)
            {
                cbb_stt.Items.Add(label);
            }
        }

        private void bt_setImgAgent_Click(object sender, EventArgs e)
        {
            OpenFileDialog opfd = new OpenFileDialog();
            opfd.Filter = "JPEG Images|*.jpg|GIF Images|*.gif|PNG Images|*.png|Bitmap Images|*.bmp";
            if (opfd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                pathImage = opfd.FileName;
                picBox_agent.Image = Image.FromFile(pathImage);
                picBox_agent.SizeMode = PictureBoxSizeMode.StretchImage;
            }
        }

        public void saveAgent()
        {
            agent = new Agent(tb_fullnameAgent.Text, tb_telFP.Text, tb_porPro.Text, tb_porPri.Text, tb_mail.Text,
                              cbb_agenceLocale.SelectedItem.ToString(), cbb_stt.SelectedItem.ToString(),
                              Tools.Aide.setPathImage(Tools.Aide.getNameImage(pathImage)));

            if (Controlleurs.AgentControlleur.save(agent))
            {
                MessageBox.Show("Sauvegarde réussie");
            }
            else
            {
                MessageBox.Show("Erreur");
            }
        }

        public void updateAgent()
        {
            agent.NomAgent = tb_fullnameAgent.Text;
            agent.TelFixePro = tb_telFP.Text;
            agent.TelPortablePro = tb_porPro.Text;
            agent.TelPortablePrive = tb_porPri.Text;
            agent.EmailAgent = tb_mail.Text;
            agent.AgenceLocale = cbb_agenceLocale.SelectedItem.ToString();

            try
            {
                agent.StatutAgent = cbb_stt.SelectedItem.ToString();
            }
            catch
            { }

            agent.PhotoAgent = Tools.Aide.setPathImage(Tools.Aide.getNameImage(pathImage));

            string cond = "ID = " + "'" + agent.IDAgent + "'";

            if (Controlleurs.AgentControlleur.update(agent, cond))
            {
                MessageBox.Show("Mise à jour réussie");
            }
            else
            {
                MessageBox.Show("Erreur");
            }
        }

        public void bindingData(Agent ag)
        {
            agent = ag;

            tb_fullnameAgent.Text = agent.NomAgent;
            tb_telFP.Text = agent.TelFixePro;
            tb_porPro.Text = agent.TelPortablePro;
            tb_porPri.Text = agent.TelPortablePrive;
            tb_mail.Text = agent.EmailAgent;
            cbb_agenceLocale.SelectedItem = agent.AgenceLocale;
            cbb_stt.SelectedItem = agent.StatutAgent;

            try
            {
                picBox_agent.Image = Image.FromFile(agent.PhotoAgent);
                picBox_agent.SizeMode = PictureBoxSizeMode.StretchImage;
            }
            catch
            { }
            
           
            loadComboBoxModified();
        }
    }
}
