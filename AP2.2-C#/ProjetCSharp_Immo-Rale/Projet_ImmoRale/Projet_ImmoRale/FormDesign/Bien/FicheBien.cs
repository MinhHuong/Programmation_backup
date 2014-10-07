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

namespace Projet_ImmoRale
{
    public partial class FicheBien : UserControl
    {
        public FicheBien()
        {
            InitializeComponent();
        }

        private void bt_setImageBien_Click(object sender, EventArgs e)
        {
            OpenFileDialog opfd = new OpenFileDialog();
            opfd.Filter = "JPEG Images|*.jpg|GIF Images|*.gif|PNG Images|*.png";
            if (opfd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                picBox_Bien.Image = Image.FromFile(opfd.FileName);
                picBox_Bien.SizeMode = PictureBoxSizeMode.StretchImage;
            }
        }
    }
}
