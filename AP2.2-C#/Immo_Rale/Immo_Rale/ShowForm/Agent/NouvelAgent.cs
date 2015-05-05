using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Immo_Rale.Controlleur;
using Immo_Rale.Tools;
using System.Windows.Forms;

namespace Immo_Rale.ShowForm.Agent
{
    public partial class NouvelAgent : UserControl
    {
        private Management.Agent obj_ag;

        public NouvelAgent(Immo_Rale.Management.Agent ag = null)
        {
            InitializeComponent();

            foreach (String agence in Configuration.Config.AGENCE_LOCALE)
            {
                cbb_Agence.Items.Add(agence);
            }
            cbb_Agence.SelectedIndex = 0;

            foreach (String stt in Configuration.Config.STATUT_AGENT)
            {
                cbb_Statut.Items.Add(stt);
            }
            cbb_Statut.SelectedIndex = 0;

            if (ag != null)
            {
                BindingData((Immo_Rale.Management.Agent)ag);
                groupBox1.Text = " Mise à jour";
            }

        }
        private void BindingData(Immo_Rale.Management.Agent ag)
        // dua cac gia tri cua Acheteur va Souhait vao textbox ( sau khi double click )
        {
            tb_statut.Visible = false;
            cbb_Statut.Visible = true;
            this.obj_ag = ag;

            bt_Enregistrer.Text = "MISE A JOUR";
            tb_Nom.Text = obj_ag.NomAgent;
            tb_Prenom.Text = obj_ag.PrenomAgent;
            tb_TelFixePro.Text = obj_ag.Telephone_Fixe_Pro;
            tb_TelPortablePrive.Text = obj_ag.Telephone_Portable_Prive;
            tb_TelPortablePro.Text = obj_ag.Telephone_Portable_Pro;
            tb_Email.Text = obj_ag.Email;
            cbb_Agence.SelectedItem = obj_ag.Agence_Locale;
            cbb_Statut.SelectedItem = obj_ag.Statut;

        }

        private void bt_Enregistrer_Click(object sender, EventArgs e)
        {
            save_process(tb_Nom.Text, tb_Prenom.Text, tb_TelFixePro.Text, tb_TelPortablePro.Text, tb_TelPortablePrive.Text,
                        tb_Email.Text, (String)cbb_Agence.SelectedItem, (String)cbb_Statut.SelectedItem, tb_statut.Text);
        }

        private void save_process(string nom, string prenom,
                                  string tel_fixe, string tel_por_pro, string tel_por_pri,
                                  string email, string agence, string statut, string statut_tb)
        {
            if (nom.Trim() == String.Empty ||
                prenom.Trim() == String.Empty ||
                tel_por_pro.Trim() == String.Empty ||
                email.Trim() == String.Empty ||
                agence.Trim() == String.Empty ||
                statut.Trim() == String.Empty)
            {
                MessageBox.Show("Valeur obligatoire !");
            }
            else
            {
                AgentControlleur ag_ctrl = new AgentControlleur();

                if (obj_ag == null)
                {
                    if (!ag_ctrl.saveAgent(nom, prenom, tel_fixe, tel_por_pro, tel_por_pri, email, agence, statut_tb))
                    {
                        MessageBox.Show("Erreur lors de la sauvegarde !");
                    }
                    else
                    {
                        MessageBox.Show("Agent sauvegardé");
                        reset_value();
                    }
                }
                else
                {
                    obj_ag.NomAgent = nom;
                    obj_ag.PrenomAgent = prenom;
                    obj_ag.Telephone_Fixe_Pro = tel_fixe;
                    obj_ag.Telephone_Portable_Prive = tel_por_pri;
                    obj_ag.Telephone_Portable_Pro = tel_por_pro;
                    obj_ag.Email = email;
                    obj_ag.Agence_Locale = agence;
                    obj_ag.Statut = statut;
                    obj_ag.Fullname = nom + " " + prenom;
                    if (!ag_ctrl.updateAgent(obj_ag))
                    {
                        MessageBox.Show("Erreur imprévue. Impossible de mettre à jour cet agent.");
                    }
                    else
                    {
                        MessageBox.Show("Mise à jour réussie.");
                        reset_value();
                    }
                }
            }
        }

        private void reset_value()
        {
            if (obj_ag != null)
            {
                obj_ag = null;
            }
            groupBox1.Text = "Nouveau Agent";
            cbb_Statut.Visible = false;
            tb_statut.Visible = true;
            tb_statut.Text = "ACTIF";
            bt_Enregistrer.Text = "ENREGISTRE";
            tb_Nom.Text = String.Empty;
            tb_Prenom.Text = String.Empty;
            tb_TelFixePro.Text = String.Empty;
            tb_TelPortablePro.Text = String.Empty;
            tb_TelPortablePrive.Text = String.Empty;
            tb_Email.Text = String.Empty;
            cbb_Agence.SelectedIndex = 0;
            cbb_Statut.SelectedIndex = 0;
        }

        private void bt_Annuler_Click(object sender, EventArgs e)
        {
            reset_value();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Parent.Parent.Visible = false;
        }

        #region Kiểm tra điều kiện dữ liệu nhập
        private void tb_TelPortablePro_Leave(object sender, EventArgs e)
        {
            if (tb_TelPortablePro.Text != "")
            {
                if (!Aide.isNumber(tb_TelPortablePro.Text))
                {
                    MessageBox.Show("Điện thoại nhập không hợp lệ");
                    tb_TelPortablePro.Text = "";
                }
            }
        }

        private void tb_Email_Leave(object sender, EventArgs e)
        {
            if (tb_Email.Text != "")
            {
                if (!Aide.isEmail(tb_Email.Text))
                {
                    MessageBox.Show("Email nhập không hợp lệ");
                    tb_Email.Text = "";
                }
            }
        }

        private void tb_TelFixePro_Leave(object sender, EventArgs e)
        {
            if (tb_TelFixePro.Text != "")
            {
                if (!Aide.isNumber(tb_TelFixePro.Text))
                {
                    MessageBox.Show("Điện thoại nhập không hợp lệ");
                    tb_TelFixePro.Text = "";
                }
            }
        }

        private void tb_TelPortablePrive_Leave(object sender, EventArgs e)
        {
            if (tb_TelPortablePrive.Text != "")
            {
                if (!Aide.isNumber(tb_TelPortablePrive.Text))
                {
                    MessageBox.Show("Điện thoại nhập không hợp lệ");
                    tb_TelPortablePrive.Text = "";
                }
            }
        } 
        #endregion
    }
}
