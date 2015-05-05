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
using Immo_Rale.ShowForm.Biens;
using System.Diagnostics; // cho cau lenh process o duoi
using PdfSharp;
using PdfSharp.Drawing;
using PdfSharp.Pdf;

namespace Immo_Rale.ShowForm.Biens
{
    public partial class Nouvelle : UserControl
     {
        private Immo_Rale.Management.Biens obj_biens;
        private Immo_Rale.Management.Vendeur obj_vendeur;
        private List<Management.Vendeur> lsVendeur;
        public event EventHandler newBiens;

        public Nouvelle(Immo_Rale.Management.Biens house = null, Immo_Rale.Management.Vendeur vend = null)
        {
            InitializeComponent();
            lsVendeur = Management.Vendeur.getList("");
            LoadInit();
            if (house != null)
            {
                BindingData((Immo_Rale.Management.Biens)house, (Immo_Rale.Management.Vendeur)vend);
            }
        }

        private void LoadInit() // hien list trong comboBox
        {
            
            // list cac thanh pho
            foreach (String role in Configuration.Config.VILLE_ROLE)
            {
                cbb_ville_pro.Items.Add(role);
                cbb_ville_bien.Items.Add(role);
            }

            // list cac kieu nha o : maison / appartement
            foreach (String role in Configuration.Config.HABITATION_ROLE)
            {
                cbb_type_habitation.Items.Add(role);
            }
            foreach (String role in Configuration.Config.STATUT_BIEN_ROLE)
            {
                cbb_statut.Items.Add(role);
            }

            cbb_type_habitation.SelectedIndex = 0; // chi vao muc dau tien trong danh sach
            cbb_ville_pro.SelectedIndex = 0;
            cbb_ville_bien.SelectedIndex = 0;
            cbb_statut.SelectedIndex = 0;
            tb_nom.Focus(); // Focus vao TextBox "Nom"
        }

        private Management.Vendeur getSelectedVendeur(string str)
        {
            // lay vendeur dau tien co ID = idvendeur trong biens
            if (Guid.Parse(str) != Guid.Empty)
                return lsVendeur.First(x => x.Id == Guid.Parse(str));
            else
                return null;
        }

        private void BindingData(Immo_Rale.Management.Biens house, Immo_Rale.Management.Vendeur vend)
            // dua cac gia tri cua vendeur va biens vao textbox ( sau khi double click )
        {
            if (house.Statutbien == "VENDU")
            {
                label25.Visible = tb_prix_vente.Visible = label26.Visible = dateTimePicker_reel.Visible = label27.Visible = tb_acheteur.Visible = true;
                dateTimePicker_reel.Value = Aide.parseDate(house.Date_vente.ToString());
            }
            groupBox1.Text = "Mise à jour";
            cbb_statut.Visible = true;
            tb_statut.Visible = false;
            this.obj_biens = house;
            this.obj_vendeur = getSelectedVendeur(house.Idvendeur);
            bt_save.Text = "ENGREGISTRE";

            tb_nom.Text = obj_vendeur.Nom;
            tb_prenom.Text = obj_vendeur.Prenom;
            tb_adresse_pro.Text = obj_vendeur.Adresse;
            cbb_ville_pro.SelectedItem = obj_vendeur.Ville;
            tb_tel_fixe.Text = obj_vendeur.Telfixe;
            tb_tel_mobile.Text = obj_vendeur.Telportable;
            tb_email.Text = obj_vendeur.Email;

            tb_surfacehabitable.Text = house.Surfacehabitable.ToString();
            tb_surfaceparcelle.Text = house.Surfaceparcelle.ToString();
            cbb_type_habitation.SelectedItem = house.Typehabitation;
            if (house.Avecgarage == "true")
                checkBox_garage.Checked = true;
            else checkBox_garage.Checked = false;
            if (house.Aveccavel == "true")
                checkBox_cave.Checked = true;
            else checkBox_cave.Checked = false;
            numericUpDown_chambre.Value = house.Nombre_chambre;
            numericUpDown_pieces.Value = house.Nombre_pieces;
            numericUpDown_bains.Value = house.Nombre_bains;
            numericUpDown_Eau.Value = house.Nombre_eau;
            tb_complementaire.Text = house.Commentaire;
            tb_adresse_bien.Text = house.Adresse;
            tb_quartier.Text = house.Quartier;
            cbb_ville_bien.SelectedItem = house.Ville;
            dateTimePicker_veut.Value = Aide.parseDate(house.Date_miseenvente.ToString());
            tb_prix_souhait.Text = house.Prixsouhait.ToString();
            tb_prix_vente.Text = house.Prixreel.ToString();
          //  dateTimePicker_reel.Value = Aide.parseDate(house.Date_vente.ToString());
            tb_acheteur.Text = house.Idacheteur.ToString();
            tb_statut.Text = house.Statutbien;
            cbb_statut.SelectedItem = house.Statutbien;

            //if (obj_biens.Vendeur != null)
            //{
            //    MessageBox.Show(obj_biens.Vendeur.Nom);
            //}
        }

        private void bt_annuler_Click(object sender, EventArgs e)
        {
            //neu double click, se hien ra control Nouvelle. Neu bam cancel, vi ID co, nen neu bam Luu lai, thi gia tri cua Bien co ID do se bi thay doi
            reset_value();           
        }
       
        private void butSave_Click(object sender, EventArgs e)
        {
            saveProcess(tb_nom.Text, tb_prenom.Text, tb_adresse_pro.Text, tb_email.Text, tb_tel_mobile.Text, tb_tel_fixe.Text, tb_surfacehabitable.Text,
                        tb_surfaceparcelle.Text, (String)cbb_ville_pro.SelectedItem, tb_adresse_bien.Text, tb_quartier.Text,
                        (String)cbb_type_habitation.SelectedItem, (String)cbb_ville_bien.SelectedItem, tb_prix_souhait.Text, tb_statut.Text,
                        checkBox_garage.Checked.ToString(), checkBox_cave.Checked.ToString(), (int)numericUpDown_chambre.Value, (int)numericUpDown_pieces.Value,
                        (int)numericUpDown_bains.Value, (int)numericUpDown_Eau.Value, tb_complementaire.Text, dateTimePicker_veut.Value.ToString(), tb_prix_vente.Text,
                        dateTimePicker_reel.Value.ToString(), tb_acheteur.Text, (String)cbb_statut.SelectedItem);
            
        }

        private void saveProcess (string s_nom, string s_prenom, string s_adresse_pro, string s_email, string s_tel_mobile, string s_tel_fixe, string s_surfacehabitable,
                                    string s_surfaceparcelle, string s_ville_pro, string s_adresse_bien, string s_quartier, string s_type_habitation, string s_ville_bien,
                                    string s_prix_souhait, string s_statut, string s_garage, string s_cave, int chambre, int pieces, int bains, int Eau, string compliment,
                                    string date_veut, string prix_vent, string date_reel, string s_acheteur, string s_statut_cbb )
        {
            if (s_nom.Trim() == String.Empty || s_prenom.Trim() == String.Empty || s_adresse_pro.Trim() == String.Empty ||
                s_email.Trim() == String.Empty || s_tel_mobile.Trim() == String.Empty || s_surfacehabitable.Trim() == String.Empty ||
                s_surfaceparcelle.Trim() == String.Empty || s_ville_pro.Trim() == String.Empty || s_adresse_bien.Trim() == String.Empty
                || s_quartier.Trim() == String.Empty || s_type_habitation.Trim() == String.Empty || s_ville_bien.Trim() == String.Empty
                || s_prix_souhait.Trim() == String.Empty || s_statut.Trim() == String.Empty)
            {
                MessageBox.Show("Value obligatoire");
            }
            else
            {
                BiensControlleur ec = new BiensControlleur();
                //new
                if (obj_biens == null)
                {
                    if (!ec.saveBiens_Vendeur(s_nom, s_prenom, s_adresse_pro, s_email, s_tel_mobile, s_tel_fixe, s_surfacehabitable,
                                                s_surfaceparcelle, s_ville_pro, s_adresse_bien, s_quartier, s_type_habitation, s_ville_bien,
                                                s_prix_souhait, s_garage, s_cave, chambre, pieces, bains, Eau, compliment, date_veut))
                        MessageBox.Show("Lỗi khi lưu hồ sơ, tạo contrat");
                    else
                    {
                        //Contrat con = new Contrat();
                        //con.Show();
                        PdfDocument pdf = new PdfDocument();
                        pdf.Info.Title = "Contrat";
                        PdfPage pdfPage = pdf.AddPage();
                        XGraphics graph = XGraphics.FromPdfPage(pdfPage);
                        XFont font = new XFont("Verdana", 20, XFontStyle.Bold);
                        int yPoint = 0;
                        graph.DrawString("CONTRAT", font, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopCenter);
                        yPoint += 40;
                        graph.DrawString("Vendeur: " + s_prenom + " " + s_nom, font, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopCenter);
                        string pdfFilename = ".\\Contrat\\Contrat.pdf";
                        pdf.Save(pdfFilename);
                        Process.Start(pdfFilename);
                        MessageBox.Show("Lưu thành công");

                        obj_biens = Management.Biens.getFirst(String.Format("DateMiseEnVente = '{0}'", date_veut));
                        newBiens(obj_biens, null);
                        reset_value();
                    }
                }
                else //edit
                {
                    obj_vendeur.Nom = s_nom;
                    obj_vendeur.Prenom = s_prenom;
                    obj_vendeur.Telfixe = s_tel_fixe;
                    obj_vendeur.Telportable = s_tel_mobile;
                    obj_vendeur.Adresse = s_adresse_pro;
                    obj_vendeur.Email = s_email;
                    obj_vendeur.Ville = s_ville_pro;

                    obj_biens.Adresse = s_adresse_bien;
                    obj_biens.Ville = s_ville_bien;
                    obj_biens.Quartier = s_quartier;
                    obj_biens.Statutbien = s_statut_cbb;
                    obj_biens.Surfacehabitable = Aide.parseInt(s_surfacehabitable);
                    obj_biens.Surfaceparcelle = Aide.parseInt(s_surfaceparcelle);
                    obj_biens.Typehabitation = s_type_habitation;
                    obj_biens.Nombre_pieces = pieces;
                    obj_biens.Nombre_chambre = chambre;
                    obj_biens.Nombre_bains = bains;
                    obj_biens.Nombre_eau = Eau;
                    obj_biens.Avecgarage = s_garage;
                    obj_biens.Aveccavel = s_cave;
                    obj_biens.Prixsouhait = Aide.parseFloat(s_prix_souhait);
                    obj_biens.Date_miseenvente = date_veut;
                    obj_biens.Prixreel = Aide.parseFloat(prix_vent);
                    obj_biens.Date_vente = date_reel;
                    //obj_biens.Idacheteur = "";
                   // obj_biens.Idvendeur = "";
                    obj_biens.Commentaire = compliment;
                    obj_biens.Nom_vendeur = s_prenom + " " + s_nom;



                    if (!ec.updateBiens_Vendeur(obj_biens, obj_vendeur))
                        MessageBox.Show("Lỗi khi cập nhật hồ sơ");
                    else
                    {
                        MessageBox.Show("Cập nhật thành công");
                        reset_value();
                    }
                }
            }
        }

        private void cbb_statut_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cbb_statut.SelectedItem.ToString() == "VENDU")
            {
                label25.Visible = tb_prix_vente.Visible = label26.Visible = dateTimePicker_reel.Visible = label27.Visible = tb_acheteur.Visible = true;
            }
            else
            {
                label25.Visible = tb_prix_vente.Visible = label26.Visible = dateTimePicker_reel.Visible = label27.Visible = tb_acheteur.Visible = false;
                dateTimePicker_reel.Checked = false;
            }
        }

        private void reset_value()
        {
            if (obj_biens != null)
            {
                obj_biens = null;
                obj_vendeur = null;
            }
            groupBox1.Text = "Nouvelle Fiche";
            bt_save.Text = "CONTRAT";
            label25.Visible = tb_prix_vente.Visible = label26.Visible = dateTimePicker_reel.Visible = label27.Visible = tb_acheteur.Visible = false;
            tb_nom.Text = tb_prenom.Text = tb_adresse_pro.Text = tb_tel_fixe.Text = tb_tel_mobile.Text = tb_email.Text = String.Empty;
            tb_surfacehabitable.Text = tb_surfaceparcelle.Text = tb_complementaire.Text = tb_adresse_bien.Text = String.Empty;
            tb_quartier.Text = tb_prix_souhait.Text = tb_prix_vente.Text = tb_acheteur.Text = String.Empty;
            tb_statut.Text = "DISPONIBLE";
            cbb_ville_pro.SelectedIndex = cbb_type_habitation.SelectedIndex = cbb_ville_bien.SelectedIndex = 0;
            checkBox_garage.Checked = checkBox_cave.Checked = dateTimePicker_reel.Checked = false;
            numericUpDown_chambre.Value = numericUpDown_pieces.Value = numericUpDown_bains.Value = numericUpDown_Eau.Value = 0;
            dateTimePicker_veut.Value = DateTime.Today;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Parent.Parent.Visible = false;
        }
        #region Kiểm tra dữ liệu ô nhập vào

        private void tb_tel_fixe_Leave(object sender, EventArgs e)
        {
            if (tb_tel_fixe.Text != "")
            {
                if (!Aide.isNumber(tb_tel_fixe.Text))
                {
                    MessageBox.Show("Điện thoại nhập không hợp lệ");
                    tb_tel_fixe.Focus();
                }
            }
        }

        private void tb_tel_mobile_Leave(object sender, EventArgs e)
        {
            if (tb_tel_mobile.Text != "")
            {
                if (!Aide.isNumber(tb_tel_mobile.Text))
                {
                    MessageBox.Show("Điện thoại nhập không hợp lệ");
                    tb_tel_mobile.Focus();
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
                    tb_email.Focus();
                }
            }
        }

        private void tb_surfacehabitable_Leave(object sender, EventArgs e)
        {
            if (tb_surfacehabitable.Text != "")
            {
                if (!Aide.isNumber(tb_surfacehabitable.Text))
                {
                    MessageBox.Show("Ô này chỉ có thể nhập số");
                    tb_surfacehabitable.Focus();
                }
            }
        }

        private void tb_surfaceparcelle_Leave(object sender, EventArgs e)
        {
            if (tb_surfaceparcelle.Text != "")
            {
                if (!Aide.isNumber(tb_surfaceparcelle.Text))
                {
                    MessageBox.Show("Ô này chỉ có thể nhập số");
                    tb_surfaceparcelle.Focus();
                }
            }
        }

        private void tb_prix_souhait_Leave(object sender, EventArgs e)
        {
            if (tb_prix_souhait.Text != "")
            {
                if (!Aide.isNumber(tb_prix_souhait.Text))
                {
                    MessageBox.Show("Ô này chỉ có thể nhập số");
                    tb_prix_souhait.Focus();
                }
            }
        }

        private void tb_prix_vente_Leave(object sender, EventArgs e)
        {
            if (tb_prix_vente.Text != "")
            {
                if (!Aide.isNumber(tb_prix_vente.Text))
                {
                    MessageBox.Show("Ô này chỉ có thể nhập số");
                    tb_prix_vente.Focus();
                }
            }
        }        
        #endregion
    }
}
