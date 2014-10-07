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
using Projet_ImmoRale.Controlleurs;
using Projet_ImmoRale.Objets;
using Projet_ImmoRale.EventRaised;

namespace Projet_ImmoRale.FormDesign
{
    public partial class ListeAgents : UserControl
    {
        public event AgentModified AgentModifiedEvent;
        private Point item_location = Point.Empty;

        public ListeAgents()
        {
            InitializeComponent();
            loadComboBox();
            initListeAgent();
        }

        private void loadComboBox()
        {
            foreach (string it in Management.Configuration.AGENCE_LOCALE)
            {
                cbb_AgenceLocale.Items.Add(it);
            }
            cbb_AgenceLocale.SelectedIndex = 0;
        }

        private void initListeAgent()
        {
            lv_Agent.View = View.Details;
            lv_Agent.Columns.Clear();

            foreach (string label in Management.Configuration.COLONNE_AGENT)
            {
                lv_Agent.Columns.Add(label);
            }

            lv_Agent.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
        }

        private void bt_findAgent_Click(object sender, EventArgs e)
        {
            lv_Agent.Items.Clear();
            string agence_choisie = cbb_AgenceLocale.SelectedItem.ToString();
            List<Agent> l_ag = null;

            if (agence_choisie == "Tout")
            {
                l_ag = Projet_ImmoRale.Controlleurs.AgentControlleur.getList("");
            }
            else
            {
                string cond = "AgenceLocale = " + "'" + agence_choisie + "'";
                l_ag = Projet_ImmoRale.Controlleurs.AgentControlleur.getList(cond);
            }

            foreach (Agent ag in l_ag)
            {
                ListViewItem it = new ListViewItem(ag.IDAgent.ToString());
                it.SubItems.Add(ag.NomAgent);
                it.SubItems.Add(ag.TelFixePro);
                it.SubItems.Add(ag.TelPortablePro);
                it.SubItems.Add(ag.TelPortablePrive);
                it.SubItems.Add(ag.EmailAgent);
                it.SubItems.Add(ag.AgenceLocale);
                it.SubItems.Add(ag.StatutAgent);
                it.SubItems.Add(ag.PhotoAgent);
               
                lv_Agent.Items.Add(it);
            }

            lv_Agent.AutoResizeColumns(ColumnHeaderAutoResizeStyle.ColumnContent);
        }

        private void MouseDown_ListView(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case System.Windows.Forms.MouseButtons.Left:
                    {
                        break;
                    }

                case System.Windows.Forms.MouseButtons.Right:
                    {
                        string[] libelles = { "Modifier", "Supprimer" };
                        ContextMenuStrip cms = new ContextMenuStrip();

                        foreach (string lib in libelles)
                        {
                            ToolStripMenuItem ts = new ToolStripMenuItem(lib);
                            ts.Click += ts_Click;
                            cms.Items.Add(ts);
                        }

                        cms.Show(lv_Agent, e.Location);
                        item_location = e.Location;

                        break;
                    }
            }
        }

        public delegate void AgentModified(object sender, AgentModifiedArg e);

        void ts_Click(object sender, EventArgs e)
        {
            ToolStripMenuItem ts = (ToolStripMenuItem)sender;
            Agent ag = new Agent();

            switch (ts.Text)
            {
                #region Modifier un Agent
                case "Modifier":
                    {
                        ListViewItem it = lv_Agent.GetItemAt(item_location.X, item_location.Y);
                        ListViewItem.ListViewSubItemCollection subIT = it.SubItems;

                        ag.IDAgent = Guid.Parse(subIT[0].Text);
                        ag.NomAgent = subIT[1].Text;
                        ag.TelFixePro = subIT[2].Text;
                        ag.TelPortablePro = subIT[3].Text;
                        ag.TelPortablePrive = subIT[4].Text;
                        ag.EmailAgent = subIT[5].Text;
                        ag.AgenceLocale = subIT[6].Text;
                        ag.StatutAgent = subIT[7].Text;
                        ag.PhotoAgent = subIT[8].Text;

                        AgentModifiedEvent(this, new AgentModifiedArg(ag));

                        break;
                    }
                #endregion

                #region Supprimer un Agent
                case "Supprimer":
                    {
                        ListViewItem it = lv_Agent.GetItemAt(item_location.X, item_location.Y);
                        string idAg = it.Text;
                        string condition = "ID = " + "'" + idAg + "'";
                        lv_Agent.Items.Remove(it);
                        Controlleurs.AgentControlleur.delete(condition);

                        break;
                    }
                #endregion
            }
        }
    }
}
