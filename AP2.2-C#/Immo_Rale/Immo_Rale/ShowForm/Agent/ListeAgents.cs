using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Immo_Rale.ShowForm.Agent
{
    public partial class ListeAgents : UserControl
    {
        private Management.Agent obj_agent = null;
        public event EventHandler AgentSelected;
        private List<Management.Agent> lsAgents;

        public ListeAgents()
        {
            InitializeComponent();

            foreach (String agence in Configuration.Config.AGENCE_LOCALE_CHERCHE)
            {
                cbb_Agence.Items.Add(agence);
            }
            cbb_Agence.SelectedIndex = 0;

            foreach (String stt in Configuration.Config.STATUT_AGENT_CHERCHE)
            {
                cbb_Statut.Items.Add(stt);
            }
            cbb_Statut.SelectedIndex = 0;
            textBox1.Text = "";
        }

        private Management.Agent getSelectedAgent(Guid id)
        {
            obj_agent = lsAgents.First(agent => agent.ID == id);
            return obj_agent;
        }

        private void bt_Chercher_Click(object sender, EventArgs e)
        {
            if (cbb_Agence.SelectedItem.ToString() == "TOUT")
                if (cbb_Statut.SelectedItem.ToString() == "TOUT")
                    lsAgents = Management.Agent.getList("");
                else
                    lsAgents = Management.Agent.getList(String.Format("Statut ='{0}'", (String)cbb_Statut.SelectedItem));
            else
                if (cbb_Statut.SelectedItem.ToString() == "TOUT")
                    lsAgents = Management.Agent.getList(String.Format("AgenceLocale = '{0}'", (String)cbb_Agence.SelectedItem));
                else
                    lsAgents = Management.Agent.getList(String.Format("AgenceLocale = '{0}' AND Statut ='{1}' ", (String)cbb_Agence.SelectedItem, (String)cbb_Statut.SelectedItem));


            dataGridView1_Agent.DataSource = lsAgents;
            dataGridView1_Agent.Columns["ID"].Visible = false;
            dataGridView1_Agent.Columns["NomAgent"].Visible = false;
            dataGridView1_Agent.Columns["PrenomAgent"].Visible = false;

            dataGridView1_Agent.Columns["Fullname"].HeaderText = "Full Name";
            dataGridView1_Agent.Columns["Agence_Locale"].HeaderText = "Site";
            dataGridView1_Agent.Columns["Telephone_Portable_Prive"].HeaderText = "Portable Privé";
            dataGridView1_Agent.Columns["Telephone_Portable_Pro"].HeaderText = "Portable Pro";
            dataGridView1_Agent.Columns["Telephone_Fixe_Pro"].HeaderText = "Tel Fixe Pro";
            dataGridView1_Agent.Columns["PrenomAgent"].Visible = false;

        }
        private void dataGridView1_Agent_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                Guid id = Guid.Parse(dataGridView1_Agent["ID", e.RowIndex].Value.ToString());
                if (id != null)
                {
                    textBox1.Text = getSelectedAgent(id).Fullname;
                }
            }
            catch
            {
                MessageBox.Show("Vui long nhap vao Khu vuc chua du lieu");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Parent.Parent.Visible = false;
        }

        private void bt_modifier_Click(object sender, EventArgs e)
        {
            if (obj_agent != null)
            {
                AgentSelected(obj_agent, null);
            }
            else
            {
                MessageBox.Show("Vui lòng click chọn Agent trong list Agent ở trên");
            }
        }

        

    }
}
