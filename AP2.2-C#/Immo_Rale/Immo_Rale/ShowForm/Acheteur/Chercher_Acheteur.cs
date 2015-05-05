using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Immo_Rale.ShowForm.Acheteur
{
    public partial class Chercher_Acheteur : UserControl
    {
        private List<Management.Agent> lsAgent;
        private List<Management.Souhait> lsSouhait;
        private List<Management.Acheteur> lsAcheteur;
        private List<Management.Visite> lsVisite;
        public event EventHandler AcheteurSelected;
        public event EventHandler SouhaitSelected;
        public event EventHandler SouhaitTrouver;
        private Management.Acheteur obj_acheteur;
        private Management.Souhait obj_souhait;
        Guid id_1 = Guid.Empty;
        Guid id_2 = Guid.Empty;

        public Chercher_Acheteur()
        {
            InitializeComponent();
            
            lsAgent = Management.Agent.getList("");
            cbb_agent_cherche.DataSource = lsAgent;
            cbb_agent_cherche.DisplayMember = "Fullname";
            cbb_agent_cherche.ValueMember = "ID";

        }

        private Management.Acheteur getSelectedAcheteur(Guid id)
        {
            obj_acheteur = lsAcheteur.First(achet => achet.Id == id);
            return obj_acheteur;
        }
        private Management.Souhait getSelectedSouhait(Guid id)
        {
            obj_souhait = lsSouhait.First(souh => souh.Id == id);
            return obj_souhait;
        }

        private void bt_chercher_Click(object sender, EventArgs e)
        {
            if (checkBox_Tout.Checked)
                lsAcheteur = Management.Acheteur.getList("");
            else
            {
                Management.Agent ag = new Management.Agent();
                ag = (Management.Agent)cbb_agent_cherche.SelectedItem;
                lsAcheteur = Management.Acheteur.getList(String.Format("idAgent = '{0}'", ag.ID));
                if (checkBox_encours.Checked)
                {
                    lsSouhait = Management.Souhait.getList("statutS =\"EN COURS\"");
                    lsAcheteur.Clear();
                    List<Management.Acheteur> lsAcheteur_temp;
                    lsAcheteur_temp = Management.Acheteur.getList(String.Format("idAgent = '{0}'", ag.ID));
                    foreach (Management.Acheteur ach in lsAcheteur_temp)
                        foreach (Management.Souhait souh in lsSouhait)
                        {
                            if (ach.Id.ToString() == souh.Id_acheteur)
                            {
                                lsAcheteur.Add(ach);
                            }
                        }
                }
            }
            dataGridView1.DataSource = lsAcheteur;
            dataGridView1.Columns["ID"].Visible = false;
            dataGridView1.Columns["Idagent"].Visible = false;

            dataGridView1.Columns["Telfixe"].HeaderText = "Tel Fixe";
            dataGridView1.Columns["Telportable"].HeaderText = "Portable";


        }

        private void checkBox_Tout_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox_Tout.Checked)
            {
                groupBox5.Visible = false;
            }
            else
            {
                groupBox5.Visible = true;
            }
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                id_1 = Guid.Parse(dataGridView1["ID", e.RowIndex].Value.ToString());
                obj_acheteur = getSelectedAcheteur(id_1);
                textBox1.Text = obj_acheteur.Nom + " " + obj_acheteur.Prenom;
                textBox2.Text = "";
                bt_modifier.Visible = false;
                bt_trouver.Visible = false;
                label6.Visible = false;
                groupBox1.Visible = groupBox2.Visible = groupBox3.Visible = label3.Visible = true;
               // bt_modify.Visible = bt_souhait.Visible = bt_visite.Visible = checkBox1.Visible = true;
                dataGridView2.DataSource = null;
            }
            catch
            {
                MessageBox.Show("Vui long double click vao ACHETEUR ban muon xem thong tin");

            }
        }

        private void dataGridView2_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                id_2 = Guid.Parse(dataGridView2["ID", e.RowIndex].Value.ToString());
                obj_souhait = getSelectedSouhait(id_2);
                textBox2.Text = id_2.ToString();
                bt_modifier.Visible = true;
                bt_trouver.Visible = true;
                //SouhaitSelected(getSelectedSouhait(id), null);
            }
            catch
            {
                MessageBox.Show("Vui long double click vao hang ban muon xem thong tin");

            }

        }

        private void bt_souhait_Click(object sender, EventArgs e)
        {
            this.dataGridView2.CellClick -= this.dataGridView2_CellClick;
            if (checkBox1.Checked)
                lsSouhait = Management.Souhait.getList(String.Format("statutS =\"EN COURS\" AND idAcheteur = '{0}'", id_1.ToString()));
            else
                lsSouhait = Management.Souhait.getList(String.Format("idAcheteur = '{0}'", id_1.ToString()));
            dataGridView2.DataSource = lsSouhait;
            dataGridView2.Columns["Id_acheteur"].Visible = false;
            dataGridView2.Columns["Nom_acheteur"].Visible = false;

            dataGridView2.Columns["Surface_habitable_min"].HeaderText = "Habitable Min";
            dataGridView2.Columns["Surface_parcelle_min"].HeaderText = "Parcelle Min";
            dataGridView2.Columns["Prix_max"].HeaderText = "Prix Max";
            dataGridView2.Columns["Chambre_min"].HeaderText = "Chambre Min";
            dataGridView2.Columns["Id"].HeaderText = "Numero Code";
            label6.Visible = true;
            this.dataGridView2.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView2_CellClick);
        }

        private void bt_modify_Click(object sender, EventArgs e)
        {
            AcheteurSelected(getSelectedAcheteur(id_1), null);
        }

        private void bt_visite_Click(object sender, EventArgs e)
        {
            //MessageBox.Show(obj_acheteur.Id.ToString());
            this.dataGridView2.CellClick -= this.dataGridView2_CellClick;
            textBox2.Text = "";
            bt_modifier.Visible = false;
            bt_trouver.Visible = false;
            label6.Visible = false;
            lsVisite = null;
            lsVisite = Management.Visite.getList(String.Format("idAcheteur = '{0}'", id_1.ToString()));
            dataGridView2.DataSource = null;
            dataGridView2.DataSource = lsVisite;
        }

        private void bt_modifier_Click(object sender, EventArgs e)
        {
            SouhaitSelected(obj_souhait, null);
        }

        private void bt_trouver_Click(object sender, EventArgs e)
        {
            SouhaitTrouver(obj_souhait, null);
        }

        

        

        

    }
}
