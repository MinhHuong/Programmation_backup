namespace Immo_Rale.ShowForm.Agent
{
    partial class ListeAgents
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.button1 = new System.Windows.Forms.Button();
            this.bt_Chercher = new System.Windows.Forms.Button();
            this.cbb_Statut = new System.Windows.Forms.ComboBox();
            this.cbb_Agence = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.dataGridView1_Agent = new System.Windows.Forms.DataGridView();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.bt_modifier = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).BeginInit();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1_Agent)).BeginInit();
            this.SuspendLayout();
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.button1);
            this.splitContainer1.Panel1.Controls.Add(this.bt_Chercher);
            this.splitContainer1.Panel1.Controls.Add(this.cbb_Statut);
            this.splitContainer1.Panel1.Controls.Add(this.cbb_Agence);
            this.splitContainer1.Panel1.Controls.Add(this.label2);
            this.splitContainer1.Panel1.Controls.Add(this.label1);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.splitContainer2);
            this.splitContainer1.Size = new System.Drawing.Size(1027, 547);
            this.splitContainer1.SplitterDistance = 100;
            this.splitContainer1.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(20, 34);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(136, 34);
            this.button1.TabIndex = 4;
            this.button1.Text = "MAIN PAGE";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // bt_Chercher
            // 
            this.bt_Chercher.Location = new System.Drawing.Point(663, 34);
            this.bt_Chercher.Name = "bt_Chercher";
            this.bt_Chercher.Size = new System.Drawing.Size(136, 34);
            this.bt_Chercher.TabIndex = 4;
            this.bt_Chercher.Text = "CHERCHER";
            this.bt_Chercher.UseVisualStyleBackColor = true;
            this.bt_Chercher.Click += new System.EventHandler(this.bt_Chercher_Click);
            // 
            // cbb_Statut
            // 
            this.cbb_Statut.FormattingEnabled = true;
            this.cbb_Statut.Location = new System.Drawing.Point(525, 41);
            this.cbb_Statut.Name = "cbb_Statut";
            this.cbb_Statut.Size = new System.Drawing.Size(132, 22);
            this.cbb_Statut.TabIndex = 3;
            // 
            // cbb_Agence
            // 
            this.cbb_Agence.FormattingEnabled = true;
            this.cbb_Agence.Location = new System.Drawing.Point(312, 41);
            this.cbb_Agence.Name = "cbb_Agence";
            this.cbb_Agence.Size = new System.Drawing.Size(138, 22);
            this.cbb_Agence.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(484, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 14);
            this.label2.TabIndex = 1;
            this.label2.Text = "Statut";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(261, 44);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(45, 14);
            this.label1.TabIndex = 0;
            this.label1.Text = "Agence";
            // 
            // splitContainer2
            // 
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.Location = new System.Drawing.Point(0, 0);
            this.splitContainer2.Name = "splitContainer2";
            this.splitContainer2.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add(this.dataGridView1_Agent);
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add(this.label4);
            this.splitContainer2.Panel2.Controls.Add(this.label3);
            this.splitContainer2.Panel2.Controls.Add(this.textBox1);
            this.splitContainer2.Panel2.Controls.Add(this.bt_modifier);
            this.splitContainer2.Size = new System.Drawing.Size(1027, 443);
            this.splitContainer2.SplitterDistance = 235;
            this.splitContainer2.TabIndex = 1;
            // 
            // dataGridView1_Agent
            // 
            this.dataGridView1_Agent.AllowUserToAddRows = false;
            this.dataGridView1_Agent.AllowUserToResizeColumns = false;
            this.dataGridView1_Agent.AllowUserToResizeRows = false;
            this.dataGridView1_Agent.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridView1_Agent.BackgroundColor = System.Drawing.SystemColors.ControlLight;
            this.dataGridView1_Agent.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1_Agent.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridView1_Agent.GridColor = System.Drawing.SystemColors.Control;
            this.dataGridView1_Agent.Location = new System.Drawing.Point(0, 0);
            this.dataGridView1_Agent.Name = "dataGridView1_Agent";
            this.dataGridView1_Agent.ReadOnly = true;
            this.dataGridView1_Agent.RowHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.Sunken;
            this.dataGridView1_Agent.RowHeadersVisible = false;
            this.dataGridView1_Agent.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridView1_Agent.Size = new System.Drawing.Size(1027, 235);
            this.dataGridView1_Agent.TabIndex = 0;
            this.dataGridView1_Agent.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_Agent_CellClick);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label4.ForeColor = System.Drawing.Color.Red;
            this.label4.Location = new System.Drawing.Point(522, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(340, 14);
            this.label4.TabIndex = 2;
            this.label4.Text = "Click vào agent trong danh sách ở trên bạn chọn lựa muốn chỉnh sửa";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Arial", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label3.Location = new System.Drawing.Point(140, 73);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(134, 17);
            this.label3.TabIndex = 2;
            this.label3.Text = "Agent bạn chọn lựa";
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("Arial", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.textBox1.Location = new System.Drawing.Point(321, 69);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(185, 25);
            this.textBox1.TabIndex = 1;
            // 
            // bt_modifier
            // 
            this.bt_modifier.Location = new System.Drawing.Point(560, 60);
            this.bt_modifier.Name = "bt_modifier";
            this.bt_modifier.Size = new System.Drawing.Size(106, 39);
            this.bt_modifier.TabIndex = 0;
            this.bt_modifier.Text = "MODIFIER";
            this.bt_modifier.UseVisualStyleBackColor = true;
            this.bt_modifier.Click += new System.EventHandler(this.bt_modifier_Click);
            // 
            // ListeAgents
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.splitContainer1);
            this.Name = "ListeAgents";
            this.Size = new System.Drawing.Size(1027, 547);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel2.ResumeLayout(false);
            this.splitContainer2.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).EndInit();
            this.splitContainer2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1_Agent)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.ComboBox cbb_Statut;
        private System.Windows.Forms.ComboBox cbb_Agence;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dataGridView1_Agent;
        private System.Windows.Forms.Button bt_Chercher;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button bt_modifier;
        private System.Windows.Forms.Label label4;
    }
}
