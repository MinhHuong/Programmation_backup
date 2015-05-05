using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Immo_Rale.ShowForm.Acheteur
{
    public partial class Date_get : Form
    {
        string date;

        public string Date
        {
            get { return date; }
            set { date = value; }
        }
        public Date_get()
        {
            InitializeComponent();
            date = "0";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            date = dateTimePicker1.Value.ToString();
            this.Close();
        }


    }
}
