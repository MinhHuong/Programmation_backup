using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics; // cho cau lenh process o duoi
using PdfSharp;
using PdfSharp.Drawing;
using PdfSharp.Pdf;

namespace Immo_Rale.ShowForm.Acheteur
{
    public partial class Propose_visite : UserControl
    {
        private List<Management.Biens> lsBien;
        private List<Management.Biens> lsBien_visite = new List<Management.Biens>();
        private Management.Souhait obj_Souhait;
        private Management.Acheteur obj_Acheteur;
        private Management.Agent obj_Agent;
        //private List<Management.Souhait> lsSouhait = new List<Management.Souhait>();

        public Propose_visite(Immo_Rale.Management.Souhait vouloir = null)
        {
            InitializeComponent();
            
            obj_Souhait = vouloir;
            init();
            dataGridView1.DataSource =lsBien;
            dataGridView1.Columns["Adresse"].HeaderText = "Địa Chỉ";
            dataGridView1.Columns["Surfacehabitable"].HeaderText = "Habitable";
            dataGridView1.Columns["Surfaceparcelle"].HeaderText = "Parcelle";
            dataGridView1.Columns["Typehabitation"].HeaderText = "Type";
            dataGridView1.Columns["Nombre_pieces"].HeaderText = "Pieces";
            dataGridView1.Columns["Nombre_chambre"].HeaderText = "Chambre";
            dataGridView1.Columns["Nombre_bains"].HeaderText = "Bains";
            dataGridView1.Columns["Avecgarage"].HeaderText = "Garage";
            dataGridView1.Columns["Aveccavel"].HeaderText = "Cave";

            dataGridView1.Columns["ID"].Visible = false;
            dataGridView1.Columns["Nom_Vendeur"].Visible = false;
            dataGridView1.Columns["prixSouhait"].Visible = false;
            dataGridView1.Columns["Date_miseenvente"].Visible = false;
            dataGridView1.Columns["prixReel"].Visible = false;
            dataGridView1.Columns["date_vente"].Visible = false;
            dataGridView1.Columns["idAcheteur"].Visible = false;
            dataGridView1.Columns["idVendeur"].Visible = false;
            dataGridView1.Columns["Statutbien"].Visible = false;
        }

        private void init()
        {
            string str = "";
            if (obj_Souhait.Prix_max != 0)
                str += " AND prixSouhait < " + obj_Souhait.Prix_max;
            if (obj_Souhait.Garage == "True")
                str += " AND avecGarage = 'True'";
            if (obj_Souhait.Cave == "True")
                str += " AND avecCave = 'True'";
            lsBien = Management.Biens.getList(String.Format("statutBien = 'DISPONIBLE' AND typeHabitation = '{0}' AND ville = '{1}' AND surfaceHabitable > {2} AND surfaceParcelle > {3} AND nombreChambres > {4}" + str,
                                                    obj_Souhait.Type, obj_Souhait.Ville, obj_Souhait.Surface_habitable_min, obj_Souhait.Surface_parcelle_min, obj_Souhait.Chambre_min));
            obj_Acheteur = Management.Acheteur.getFirst(String.Format("ID = '{0}'", obj_Souhait.Id_acheteur));
            obj_Agent = Management.Agent.getFirst(String.Format("ID = '{0}'", obj_Acheteur.Idagent));
        }

        private void bt_Xuat_Click(object sender, EventArgs e)
        {
            if (lsBien.Count == 0)
                MessageBox.Show("Khong co nha nao phu hop voi yeu cau, thu lai khi khac sau");
            else
            {
                int i = 1;
                PdfDocument pdf = new PdfDocument();
                pdf.Info.Title = "PROPOSITION";
                PdfPage pdfPage = pdf.AddPage();
                XGraphics graph = XGraphics.FromPdfPage(pdfPage);
                XFont font_to = new XFont("Verdana", 20, XFontStyle.Bold);
                XFont font_medium = new XFont("Verdana", 14, XFontStyle.Bold);
                XFont font_small_bold = new XFont("Verdana", 12, XFontStyle.Bold);
                XFont font_small = new XFont("Verdana", 12, XFontStyle.Regular);
                int yPoint = 0;
                graph.DrawString("LISTE BIENS DE PROPOSITION", font_to, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopCenter);
                yPoint += 40;
                graph.DrawString("DATE: " + DateTime.Today.ToShortDateString(), font_medium, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                yPoint += 25;
                graph.DrawString("DEMANDEUR: " + obj_Acheteur.Prenom + " " +obj_Acheteur.Nom + "         Tel:" + obj_Acheteur.Telportable, font_medium, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                yPoint += 25;                
                graph.DrawString("COMMERCIAL: " + obj_Agent.PrenomAgent + " " + obj_Agent.NomAgent + "         Tel:" + obj_Agent.Telephone_Portable_Pro, font_medium, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                yPoint += 25;
                graph.DrawString("\t BIENS", font_medium, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                yPoint += 25;
                foreach (Management.Biens obj_bien in lsBien)
                {
                    graph.DrawString(i.ToString()+ ").", font_small_bold, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                    yPoint += 20;
                    graph.DrawString("  _Ville: " + obj_bien.Ville, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                    yPoint += 20;
                    graph.DrawString("  _Quartier: " + obj_bien.Quartier, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                    yPoint += 20;
                    graph.DrawString("  _Type: " + obj_bien.Typehabitation, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                    yPoint += 20;
                    graph.DrawString("  _Surface Habitable: " + obj_bien.Surfacehabitable, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                    yPoint += 20;
                    graph.DrawString("  _Surface de la parcelle: " + obj_bien.Surfaceparcelle, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                    yPoint += 20;
                    graph.DrawString("  _Chambre: " + obj_bien.Nombre_chambre + "     Pieces: " + obj_bien.Nombre_pieces, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                    yPoint += 20;
                    graph.DrawString("  _Garage: " + obj_bien.Avecgarage + "      Cave: " + obj_bien.Aveccavel, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
                    yPoint += 20;
                    i++;
                }
               string pdfFilename = ".\\Propose\\proposition.pdf";
                pdf.Save(pdfFilename);
                Process.Start(pdfFilename);
            }

        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                Guid id = Guid.Parse(dataGridView1["ID", e.RowIndex].Value.ToString());
                if (id != null)
                {
                    bool check = true;
                    Management.Biens obj_biens = new Management.Biens();
                    obj_biens = Management.Biens.getFirst(String.Format("ID = '{0}'", id.ToString()));
                    foreach (Management.Biens b in lsBien_visite)
                        if (obj_biens.Id == b.Id)
                            check = false;
                    if (check)
                        lsBien_visite.Add(obj_biens);
                    else MessageBox.Show("Da co doi tuong nay trong danh sach liste Visite");
                }
                
                dataGridView2.DataSource = null;
                dataGridView2.DataSource = lsBien_visite;

                dataGridView2.Columns["Adresse"].HeaderText = "Địa Chỉ";
                dataGridView2.Columns["Surfacehabitable"].HeaderText = "Habitable";
                dataGridView2.Columns["Surfaceparcelle"].HeaderText = "Parcelle";
                dataGridView2.Columns["Typehabitation"].HeaderText = "Type";
                dataGridView2.Columns["Nombre_pieces"].HeaderText = "Pieces";
                dataGridView2.Columns["Nombre_chambre"].HeaderText = "Chambre";
                dataGridView2.Columns["Nombre_bains"].HeaderText = "Bains";
                dataGridView2.Columns["Avecgarage"].HeaderText = "Garage";
                dataGridView2.Columns["Aveccavel"].HeaderText = "Cave";

                dataGridView2.Columns["ID"].Visible = false;
                dataGridView2.Columns["Nom_Vendeur"].Visible = false;
                dataGridView2.Columns["prixSouhait"].Visible = false;
                dataGridView2.Columns["Date_miseenvente"].Visible = false;
                dataGridView2.Columns["prixReel"].Visible = false;
                dataGridView2.Columns["date_vente"].Visible = false;
                dataGridView2.Columns["idAcheteur"].Visible = false;
                dataGridView2.Columns["idVendeur"].Visible = false;
                dataGridView2.Columns["Statutbien"].Visible = false;
            }
            catch
            {
                MessageBox.Show("Vui long click vao khu vuc chua du lieu");
            }

        }

        private void dataGridView2_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                Guid id = Guid.Parse(dataGridView2["ID", e.RowIndex].Value.ToString());
                if (id != null)
                {
                    Management.Biens obj_biens = new Management.Biens();

                    foreach (Management.Biens b in lsBien_visite)
                        if (b.Id == id)
                        {
                            lsBien_visite.Remove(b);
                            break;
                        }
                }
                dataGridView2.DataSource = null;
                dataGridView2.DataSource = lsBien_visite;
                dataGridView2.Columns["ID"].Visible = false;
                dataGridView2.Columns["Nom_Vendeur"].Visible = false;
                dataGridView2.Columns["prixSouhait"].Visible = false;
                dataGridView2.Columns["Date_miseenvente"].Visible = false;
                dataGridView2.Columns["prixReel"].Visible = false;
                dataGridView2.Columns["date_vente"].Visible = false;
                dataGridView2.Columns["idAcheteur"].Visible = false;
                dataGridView2.Columns["idVendeur"].Visible = false;
                dataGridView2.Columns["Statutbien"].Visible = false;
            }
            catch
            {
                MessageBox.Show("Vui long click vao khu vuc chua du lieu");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Management.Visite vis = new Management.Visite();
            if (lsBien_visite.Count != 0)
            {
                foreach (Management.Biens b in lsBien_visite)
                {
                    vis.Id_biens = b.Id;
                    vis.Id_agent = obj_Agent.ID;
                    vis.Id_acheteur = obj_Acheteur.Id;
                    Date_get date = new Date_get();
                    date.ShowDialog();
                    vis.Date = date.Date;
                    Management.Visite.insert(vis);
                    printToPDF(vis.Date, b);
                }
                Parent.Parent.Visible = false;
            }
            else MessageBox.Show("Vui long chon BIENS o tren de dua vao danh sach");
           
        }

        private void printToPDF(string date, Management.Biens bien)
        {
            PdfDocument pdf = new PdfDocument();
            pdf.Info.Title = "BON DE VISITE";
            PdfPage pdfPage = pdf.AddPage();
            XGraphics graph = XGraphics.FromPdfPage(pdfPage);
            XFont font_to = new XFont("Verdana", 20, XFontStyle.Bold);
            XFont font_medium = new XFont("Verdana", 14, XFontStyle.Bold);
            XFont font_small_bold = new XFont("Verdana", 12, XFontStyle.Bold);
            XFont font_small = new XFont("Verdana", 12, XFontStyle.Regular);
            int yPoint = 40;
            graph.DrawString("BON DE VISITE", font_to, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopCenter);
            yPoint += 80;
            graph.DrawString("DATE: " + date, font_medium, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint += 40;
            graph.DrawString("DEMANDEUR: " + obj_Acheteur.Prenom + " " + obj_Acheteur.Nom + "         Tel:" + obj_Acheteur.Telportable, font_medium, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint += 25;
            graph.DrawString("COMMERCIAL: " + obj_Agent.PrenomAgent + " " + obj_Agent.NomAgent + "         Tel:" + obj_Agent.Telephone_Portable_Pro, font_medium, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint += 40;
            graph.DrawString("\t DETAIL DE BIENS:", font_medium, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint += 25;

            graph.DrawString("  _Ville: " + bien.Ville, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint += 20;
            graph.DrawString("  _Quartier: " + bien.Quartier, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint += 20;
            graph.DrawString("  _Type: " + bien.Typehabitation, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint += 20;
            graph.DrawString("  _Surface Habitable: " + bien.Surfacehabitable, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint += 20;
            graph.DrawString("  _Surface de la parcelle: " + bien.Surfaceparcelle, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint += 20;
            graph.DrawString("  _Chambre: " + bien.Nombre_chambre + "     Pieces: " + bien.Nombre_pieces, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint += 20;
            graph.DrawString("  _Garage: " + bien.Avecgarage + "      Cave: " + bien.Aveccavel, font_small, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint += 60;

            graph.DrawString("Toi da di xem nha va toi chap nhan voi nhung dieu khoan cua cong ty", font_small_bold, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);
            yPoint +=  60;

            graph.DrawString("                     Signature de CLIENT", font_medium, XBrushes.Black, new XRect(0, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);

            string pdfFilename = ".\\Visite\\Visite" +date + ".pdf";
            pdfFilename = pdfFilename.Replace("/", "-");
            pdfFilename = pdfFilename.Replace(":", "_");
            pdf.Save(pdfFilename);
            Process.Start(pdfFilename);
        }

        

        



  

    }
}
