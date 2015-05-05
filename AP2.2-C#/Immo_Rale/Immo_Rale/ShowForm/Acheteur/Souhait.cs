using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Immo_Rale.Tools;
using Immo_Rale.Controlleur;

namespace Immo_Rale.ShowForm.Acheteur
{
    public partial class Souhait : UserControl
    {
        private Immo_Rale.Management.Souhait obj_Souhait;
        private Immo_Rale.Management.Acheteur obj_Acheteur;
        private List<Management.Acheteur> lsAcheteur;
        private List<Management.Agent> lsAgent;
        public event EventHandler trouver_souhait;

        public Souhait(Immo_Rale.Management.Souhait vouloir = null, Immo_Rale.Management.Acheteur achette = null)
        {            
            InitializeComponent();
            groupBox_Souhait.Text = "Nouveau Souhait";
            lsAcheteur = Management.Acheteur.getList("");
            lsAgent = Management.Agent.getList("");
            LoadInit();
            if (vouloir != null || achette != null)
            {
                groupBox_Souhait.Text = "Mise À Jour";
                BindingData((Immo_Rale.Management.Souhait)vouloir, (Immo_Rale.Management.Acheteur)achette);
            }
        }

        private void LoadInit() // hien list trong comboBox
        {
            cbb_agent.DataSource = lsAgent;
            cbb_agent.DisplayMember = "FullName";
            cbb_agent.ValueMember = "ID";
            foreach (String role in Configuration.Config.VILLE_ROLE)
            {
                cbb_villesouhait.Items.Add(role);
            }

            // list cac kieu nha o : maison / appartement
            foreach (String role in Configuration.Config.HABITATION_ROLE)
            {
                cbb_type.Items.Add(role);
            }

            cbb_type.SelectedIndex = 0; // chi vao muc dau tien trong danh sach
            cbb_villesouhait.SelectedIndex = 0;
            tb_nom.Focus(); // Focus vao TextBox "Nom"
        }

        private Management.Acheteur getSelectedAcheteur(string str)
        {
            // lay Acheteur dau tien co ID = idAcheteur trong Souhait
            if (Guid.Parse(str) != Guid.Empty)
                return lsAcheteur.First(x => x.Id == Guid.Parse(str));
            else
                return null;
        }

        private void BindingData(Immo_Rale.Management.Souhait vouloir, Immo_Rale.Management.Acheteur achette)
            // dua cac gia tri cua Acheteur va Souhait vao textbox ( sau khi double click )
        {
            this.obj_Souhait = vouloir;
            if(vouloir != null)
                this.obj_Acheteur = getSelectedAcheteur(vouloir.Id_acheteur);
            else
                this.obj_Acheteur = achette;// getSelectedAcheteur(vouloir.Id_acheteur);
           // bt_find.Text = "ENGREGISTRE";

            tb_nom.Text = obj_Acheteur.Nom;
            tb_prenom.Text = obj_Acheteur.Prenom;
            tb_adresse.Text = obj_Acheteur.Adresse;
            //cbb_ville_pro.SelectedItem = obj_Acheteur;
            tb_telfixe.Text = obj_Acheteur.Telfixe;
            tb_telportable.Text = obj_Acheteur.Telportable;
            tb_email.Text = obj_Acheteur.Email;
            // thieu agent ... nho them vao
            if (obj_Souhait != null)
            {
                tb_habitablemin.Text = vouloir.Surface_habitable_min.ToString();
                tb_parcellemin.Text = vouloir.Surface_parcelle_min.ToString();
                cbb_type.SelectedItem = vouloir.Type;
                if (vouloir.Garage == "True")
                    cb_garage.Checked = true;
                else cb_garage.Checked = false;
                if (vouloir.Cave == "True")
                    cb_cave.Checked = true;
                else cb_cave.Checked = false;
                num_chambre.Value = Aide.parseInt(vouloir.Chambre_min.ToString());
                cbb_villesouhait.SelectedItem = vouloir.Ville;
                tb_prix.Text = vouloir.Prix_max.ToString();
                //tb_fullname.Text = vouloir.Idacheteur.ToString(); //khong can, vi chi can de khi hien database len co ten cho de nhin
                tb_statut.Text = vouloir.Statut;
            }

            //if (obj_Souhait.Acheteur != null)
            //{
            //    MessageBox.Show(obj_Souhait.Acheteur.Nom);
            //}
        }

        private void bt_annuler_Click(object sender, EventArgs e)
        {
            if (obj_Souhait != null)
            {
                obj_Souhait = null;
            }
            if (obj_Acheteur != null)
            {
                obj_Acheteur = null;
            }
            tb_nom.Text = tb_prenom.Text = tb_adresse.Text = tb_telfixe.Text = tb_telportable.Text = tb_email.Text = String.Empty;
            tb_prix.Text = tb_habitablemin.Text = tb_parcellemin.Text = "0";
            tb_statut.Text = "EN COURS";
            cbb_type.SelectedIndex = cbb_villesouhait.SelectedIndex = 0;
            cb_cave.Checked = cb_garage.Checked = false;
            num_chambre.Value = 0;
        }
       
        private void butSave_Click(object sender, EventArgs e)
        {
            saveProcess(tb_nom.Text, tb_prenom.Text, tb_adresse.Text, tb_email.Text, tb_telportable.Text, tb_telfixe.Text, tb_habitablemin.Text,
                        tb_parcellemin.Text, (String)cbb_type.SelectedItem,
                        (String)cbb_villesouhait.SelectedItem, tb_statut.Text,
                        cb_garage.Checked.ToString(), cb_cave.Checked.ToString(), (int)num_chambre.Value,
                        tb_prix.Text, (Management.Agent)cbb_agent.SelectedItem);
            
                        
        }

        private void saveProcess(string s_nom, string s_prenom, string s_adresse, string s_email, string s_tel_mobile, string s_tel_fixe, string s_habitablemin,
                                    string s_parcellemin, string s_type,string s_villesouhait, 
                                    string s_statut, string s_garage, string s_cave, int chambre,
                                    string prix, Management.Agent agent)
        {
            if (s_nom.Trim() == String.Empty || s_prenom.Trim() == String.Empty || s_adresse.Trim() == String.Empty ||
                s_email.Trim() == String.Empty || s_tel_mobile.Trim() == String.Empty || s_tel_fixe.Trim() == String.Empty || 
                prix.Trim() == String.Empty || s_habitablemin.Trim() == String.Empty || s_parcellemin.Trim() == String.Empty)
            {
                MessageBox.Show("Value obligatoire");
            }
            else
            {
                SouhaitControlleur ec = new SouhaitControlleur();
                //new
                if (obj_Souhait == null && obj_Acheteur == null)
                {
                    if (!ec.saveSouhait_Acheteur(s_nom, s_prenom, s_adresse, s_email, s_tel_mobile, s_tel_fixe, s_habitablemin,
                                                s_parcellemin, s_villesouhait, s_type, s_statut,
                                                s_garage, s_cave, chambre, prix, agent))
                        MessageBox.Show("Lỗi khi lưu hồ sơ, tạo contrat");
                    else
                    {
                        if (MessageBox.Show("Lưu thành công. Bạn muốn tìm Biens phù hợp không?", "Thông Báo", MessageBoxButtons.YesNo) == DialogResult.Yes)
                        {

                            trouver_souhait(getSouhait(s_habitablemin, s_parcellemin, s_type, s_villesouhait, s_statut,
                                                s_garage, s_cave, chambre, prix, s_nom, s_prenom), null);
                        }
                    }
                }
                else //edit
                {
                    if (obj_Souhait == null)
                    {
                        if (!ec.newSouhait_oldAcheteur(obj_Acheteur, s_habitablemin,
                                                    s_parcellemin, s_villesouhait, s_type, s_statut,
                                                    s_garage, s_cave, chambre, prix))
                            MessageBox.Show("Lỗi khi lưu hồ sơ, tạo contrat");
                        else
                        {
                            //MessageBox.Show("Lưu thành công");
                            if (MessageBox.Show("Cập nhật thành công. Bạn muốn tìm Biens phù hợp không?", "Thông Báo", MessageBoxButtons.YesNo) == DialogResult.Yes)
                                trouver_souhait(getSouhait(s_habitablemin, s_parcellemin, s_type, s_villesouhait, s_statut,
                                                s_garage, s_cave, chambre, prix, s_nom, s_prenom), null);
                        }

                    }
                    else
                    {
                        obj_Acheteur.Nom = s_nom;
                        obj_Acheteur.Prenom = s_prenom;
                        obj_Acheteur.Telfixe = s_tel_fixe;
                        obj_Acheteur.Telportable = s_tel_mobile;
                        obj_Acheteur.Idagent = agent.ID.ToString();
                        obj_Acheteur.Email = s_email;
                        obj_Acheteur.Adresse = s_adresse;

                        obj_Souhait.Statut = s_statut;
                        obj_Souhait.Ville = s_villesouhait;
                        obj_Souhait.Type = s_type;
                        obj_Souhait.Surface_habitable_min = Aide.parseInt(s_habitablemin); ;
                        obj_Souhait.Surface_parcelle_min = Aide.parseInt(s_parcellemin);
                        obj_Souhait.Chambre_min = chambre;
                        obj_Souhait.Cave = s_cave;
                        obj_Souhait.Garage = s_garage;
                        obj_Souhait.Prix_max = Aide.parseFloat(prix);

                        if (!ec.updateSouhait_Acheteur(obj_Souhait, obj_Acheteur))
                            MessageBox.Show("Lỗi khi cập nhật hồ sơ");
                        else
                        {
                            if (MessageBox.Show("Cập nhật thành công. Bạn muốn tìm Biens phù hợp không?", "Thông Báo", MessageBoxButtons.YesNo) == DialogResult.Yes)
                            {
                                //MessageBox.Show("Cập nhật thành công");
                                trouver_souhait(obj_Souhait, null);
                            }
                        }
                    }
                }
            }
        }

        private Management.Souhait getSouhait(string s_habitablemin, string s_parcellemin, string s_type, string s_villesouhait,
                                    string s_statut, string s_garage, string s_cave, int chambre, string prix, string s_nom, string s_prenom)
        {
            Management.Souhait temp = new Management.Souhait();
            if (obj_Souhait == null)
            {
                string condition = "typeS = \"" + s_type + "\" AND surfacehabiteMin = \"" + s_habitablemin +
                                    "\" AND surfaceparcelleMin = \"" + s_parcellemin + "\" AND aveccaveS = \"" + s_cave +
                                    "\" AND avecgarageS = \"" + s_garage + "\" AND villeS = \"" + s_villesouhait +
                                    "\" AND prixMax = \"" + prix + "\" AND nomAcheteur = \"" + s_prenom + " " + s_nom + "\"";

                temp = Management.Souhait.getFirst(condition);
                
            }
            return temp;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Parent.Parent.Visible = false;
        }

        #region Kiểm tra dữ liệu nhập vào textbox
        private void tb_habitablemin_Leave(object sender, EventArgs e)
        {
            if (tb_habitablemin.Text != "")
            {
                if (!Aide.isNumber(tb_habitablemin.Text))
                {
                    MessageBox.Show("Ô này chỉ có thể nhập số");
                    tb_habitablemin.Focus();
                }
            }
        }

        private void tb_parcellemin_Leave(object sender, EventArgs e)
        {
            if (tb_parcellemin.Text != "")
            {
                if (!Aide.isNumber(tb_parcellemin.Text))
                {
                    MessageBox.Show("Ô này chỉ có thể nhập số");
                    tb_parcellemin.Focus();
                }
            }
        }

        private void tb_telfixe_Leave(object sender, EventArgs e)
        {
            if (tb_telfixe.Text != "")
            {
                if (!Aide.isNumber(tb_telfixe.Text))
                {
                    MessageBox.Show("Điện Thoại bạn nhập sai quy cách. Nhập theo quy cách vd: 0084909123456");
                    tb_telfixe.Focus();
                }
            }
        }

        private void tb_telportable_Leave(object sender, EventArgs e)
        {
            if (tb_telportable.Text != "")
            {
                if (!Aide.isNumber(tb_telportable.Text))
                {
                    MessageBox.Show("Điện Thoại bạn nhập sai quy cách. Nhập theo quy cách vd: 0084909123456");
                    tb_telportable.Focus();
                }
            }
        }

        private void tb_email_Leave(object sender, EventArgs e)
        {
            if (tb_email.Text != "")
            {
                if (!Aide.isEmail(tb_email.Text))
                {
                    MessageBox.Show("Email nhập không hợp lệ");
                    tb_email.Focus();// = true;
                }
            }
        }
        #endregion
    }
}
