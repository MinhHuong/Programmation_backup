using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Immo_Rale.ShowForm.Biens;
using Immo_Rale.ShowForm.Acheteur;
using Immo_Rale.ShowForm.Agent;
using Immo_Rale.Management;
using Immo_Rale.Tools;

namespace Immo_Rale.ShowForm
{
    public partial class MainPage : Form
    {
       // private UserControl current;
        //private static TabControl tabControl;
        private bool reverse = true;
        private int run;
        int vitri = 0;
        private Management.Biens obj_biens;
        private List<Management.Biens> ls_biens;
        private List<Management.Biens> ls_temp_biens;
       
        public MainPage()
        {
            InitializeComponent();
            ls_temp_biens = new List<Management.Biens>();
            init();
            run = splitContainer1.Width;
            timer1.Enabled = true;
            if (obj_biens != null)
                annonce();
           // tabControl = tabControl_Agent;
           // changeTab(tabPage1_Biens, new NouvelAgent());
        }
        private void init() // hien nhung Biens moi nhap vao trong vong 1 ngay moi day
        {
            vitri = 0;
            obj_biens = null;
            ls_biens = null;
            ls_biens = Management.Biens.getList("statutbien='DISPONIBLE'");
            if (ls_biens.Count != 0)
            {
                foreach (Management.Biens b in ls_biens)
                {
                    DateTime dateTimeStart = Aide.parseDate(b.Date_miseenvente);
                    DateTime dateTimeEnd = DateTime.Today;
                    TimeSpan interval = dateTimeEnd - dateTimeStart;
                    double totalDays = interval.TotalDays;
                    if (totalDays < 3) // Biens chỉ thông báo 2 ngày gần đây
                    {
                        ls_temp_biens.Add(b);
                       // MessageBox.Show(totalDays.ToString() + "    " + b.Date_miseenvente);
                    }
                }
                ls_biens = null;
                if (ls_temp_biens.Count != 0)
                    obj_biens = ls_temp_biens[vitri];
            }            
        }
        private void change_Biens()
        {
            if (obj_biens != null)
                annonce();
            else label1.Text = "Không có BIENS mới nào trong 2 ngày qua";

            if (ls_temp_biens.Count != 0)
                vitri++;
            if (vitri < ls_temp_biens.Count)
                obj_biens = ls_temp_biens[vitri];
            else {init(); }
        }

        private void annonce()
        {
            string str = "Căn hộ là " + obj_biens.Typehabitation+ " có địa chỉ: " + obj_biens.Adresse +"   Ville: " + obj_biens.Ville + "   Surface habitable: " + obj_biens.Surfacehabitable;
            str += "   Surface parcelle: " + obj_biens.Surfaceparcelle + "   pieces: " + obj_biens.Nombre_pieces + "   Prix: " + obj_biens.Prixsouhait + " euros";
            label1.Text = str;
        }

        private void changeTab(TabPage tab, UserControl uc)
        {
            uc.Size = tab.Size;
            tab.Controls.Clear();
            uc.Dock = DockStyle.Fill;
            tab.Controls.Add(uc);
        }

        private void tabControl_Biens_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl_Biens.SelectedTab == tabPage1_Biens)
            {
                Nouvelle uc = new Nouvelle();
                uc.newBiens += (s1, e1) =>
                {
                    reverse = true;
                    run = splitContainer1.Width;
                    init();
                    obj_biens = (Immo_Rale.Management.Biens)s1;
                    annonce();
                };                
                changeTab(tabPage1_Biens, uc);
            }
            else if (tabControl_Biens.SelectedTab == tabPage2_Biens)
            {
                Liste_bien uc = new Liste_bien();
                uc.BiensSelected += (s2, e1) =>
                {
                    tabControl_Biens.SelectedTab = tabPage1_Biens;
                    changeTab(tabPage1_Biens, new Nouvelle((Immo_Rale.Management.Biens)s2));
                };
                changeTab(tabPage2_Biens, uc);
            }
        }

        private void tabControl_Acheteur_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl_Acheteur.SelectedTab == tabPage1_Acheteur)
            {                
                init_souhait();
            }
            else if (tabControl_Acheteur.SelectedTab == tabPage2_Acheteur)
            {
                Chercher_Acheteur cher = new Chercher_Acheteur();
                tabPage1_Acheteur.Text = "Fiche Souhait";
                cher.AcheteurSelected += (s1, e1) =>
                    {
                        tabControl_Acheteur.SelectedTab = tabPage1_Acheteur;
                        init_souhait(null, (Management.Acheteur)s1);
                        //changeTab(tabPage1_Acheteur, new Immo_Rale.ShowForm.Acheteur.Souhait(null, (Management.Acheteur)s1));
                    };
                cher.SouhaitSelected += (s1, e1) =>
                    {
                        tabControl_Acheteur.SelectedTab = tabPage1_Acheteur;
                        init_souhait((Management.Souhait)s1, null);
                        //changeTab(tabPage1_Acheteur, new Immo_Rale.ShowForm.Acheteur.Souhait((Management.Souhait)s1, null));
                    };
                cher.SouhaitTrouver += (s1, e1) =>
                {
                    tabPage1_Acheteur.Text = " Biens Trouver";
                    tabControl_Acheteur.SelectedTab = tabPage1_Acheteur;
                    changeTab(tabPage1_Acheteur, new ShowForm.Acheteur.Propose_visite((Management.Souhait)s1));
                    //changeTab(tabPage1_Acheteur, new Immo_Rale.ShowForm.Acheteur.Souhait((Management.Souhait)s1, null));
                };
                changeTab(tabPage2_Acheteur, cher);
            }

        }

        private void tabControl_Agent_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl_Agent.SelectedTab == tabPage1_Agent)
            {
                changeTab(tabPage1_Agent, new NouvelAgent());
            }
            else if (tabControl_Agent.SelectedTab == tabPage2_Agents)
            {
                ListeAgents la = new ListeAgents();

                la.AgentSelected += (s1, e1) =>
                {
                    tabControl_Agent.SelectedTab = tabPage1_Agent;
                    changeTab(tabPage1_Agent, new NouvelAgent((Immo_Rale.Management.Agent)s1));
                };

                changeTab(tabPage2_Agents, la);
            }
        }

        private void bt_Biens_Click(object sender, EventArgs e)
        {
            Nouvelle uc = new Nouvelle();
            uc.newBiens += (s1, e1) =>
            {
                reverse = true;
                run = splitContainer1.Width;
                init();
                obj_biens = (Immo_Rale.Management.Biens)s1;
                annonce();
            };
            changeTab(tabPage1_Biens, uc);
            tabControl_Biens.SelectedIndex = 0;
            tabControl_Biens.Visible = true;
            tabControl_Acheteur.Visible = false;
            tabControl_Agent.Visible = false;
        }

        private void bt_Acheteur_Click(object sender, EventArgs e)
        {
            init_souhait();
            tabPage1_Acheteur.Text = "Fiche Souhait";
            tabControl_Acheteur.SelectedIndex = 0;
            tabControl_Biens.Visible = false;
            tabControl_Acheteur.Visible = true;
            tabControl_Agent.Visible = false;
        }

        private void bt_Agent_Click(object sender, EventArgs e)
        {
            tabControl_Biens.Visible = false;
            tabControl_Acheteur.Visible = false;
            tabControl_Agent.Visible = true;
            tabControl_Agent.SelectedIndex = 0;
            changeTab(tabPage1_Agent, new NouvelAgent());
        }

        private void bt_info_Click(object sender, EventArgs e)
        {

        }

        private void init_souhait(Management.Souhait sou = null, Management.Acheteur achet = null)
        {
            Immo_Rale.ShowForm.Acheteur.Souhait souh = new Immo_Rale.ShowForm.Acheteur.Souhait(sou, achet);
            souh.trouver_souhait += (s1, e1) =>
            {
                tabPage1_Acheteur.Text = " Biens Trouver";
                changeTab(tabPage1_Acheteur, new ShowForm.Acheteur.Propose_visite((Management.Souhait)s1));
            };
            changeTab(tabPage1_Acheteur, souh);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label1.Location = new System.Drawing.Point(run, 6);
            if (run > splitContainer1.Width) { reverse = true; change_Biens(); }
            else if (run < 0) reverse = false;
            if (reverse)
            {
                run--;                
            }
            else run++;
        }


        
        

    }
}
