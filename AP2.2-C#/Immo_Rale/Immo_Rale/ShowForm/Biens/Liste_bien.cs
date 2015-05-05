using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Immo_Rale.ShowForm.Biens
{
    public partial class Liste_bien : UserControl
    {
        private Management.Biens obj_biens;

        public Liste_bien()
        {
            InitializeComponent();
            foreach (String role in Configuration.Config.STATUT_BIEN_ROLE)
            {
                cbb_statut.Items.Add(role);
            }
            cbb_statut.SelectedIndex = 0;
        }

        private List<Management.Biens> lsBiens;
        //private List<Management.Vendeur> lsVendeur;
        public event EventHandler BiensSelected;

        private Management.Biens getSelectedBiens(Guid id)
        {
            obj_biens = lsBiens.First(biens => biens.Id == id);
            return obj_biens;
        }

        private void dataGridView1_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
           
            try
            {
                Guid id = Guid.Parse(dataGridView1["ID", e.RowIndex].Value.ToString()); 
                if (id != null)
                {
                    BiensSelected(getSelectedBiens(id), null);
                }
            }
            catch 
            {
                MessageBox.Show("Vui long click vao khu vuc data");
            }
            
        }

        private void bt_chercher_Click(object sender, EventArgs e)
        {
             lsBiens = Management.Biens.getList(String.Format("statutbien='{0}'", (String)cbb_statut.SelectedItem));
            //lsVendeur = Management.Vendeur.getList("");
            dataGridView1.DataSource = lsBiens;
            dataGridView1.Columns["ID"].Visible = false;
            dataGridView1.Columns["idVendeur"].Visible = false;
            dataGridView1.Columns["idacheteur"].Visible = false;

            dataGridView1.Columns["Nom_vendeur"].HeaderText = "Chủ Sở Hữu";
            dataGridView1.Columns["Statutbien"].HeaderText = "Statut";
            dataGridView1.Columns["Surfacehabitable"].HeaderText = "Habitable";
            dataGridView1.Columns["Surfaceparcelle"].HeaderText = "Parcelle";
            dataGridView1.Columns["Typehabitation"].HeaderText = "Type";
            dataGridView1.Columns["Nombre_pieces"].HeaderText = "Pieces";
            dataGridView1.Columns["Nombre_chambre"].HeaderText = "Chambre";
            dataGridView1.Columns["Nombre_bains"].HeaderText = "Bains";
            dataGridView1.Columns["Avecgarage"].HeaderText = "Garage";
            dataGridView1.Columns["Aveccavel"].HeaderText = "Cave";
            dataGridView1.Columns["Prixsouhait"].HeaderText = "Prix";
            dataGridView1.Columns["Date_miseenvente"].HeaderText = "Date Ajoute";
           // (String)cbb_type.SelectedItem  String.Format("id='{0}'", idvendeur)
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Parent.Parent.Visible = false;
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {

            try
            {
                Guid id = Guid.Parse(dataGridView1["ID", e.RowIndex].Value.ToString());
                if (id != null)
                {
                    obj_biens = getSelectedBiens(id);
                    textBox1.Text = obj_biens.Nom_vendeur;
                    //BiensSelected(getSelectedBiens(id), null);
                }
            }
            catch
            {
                MessageBox.Show("Vui long click vao khu vuc data");
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (obj_biens != null)
            {
                BiensSelected(obj_biens, null);
            }
            else MessageBox.Show("Bạn chưa chọn Biens để cập nhật thông tin, vui lòng chọn Biens trong danh sách Biens sau khi tìm kiếm");

        }

    }
}
