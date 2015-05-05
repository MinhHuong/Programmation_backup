namespace Immo_Rale.ShowForm
{
    partial class MainPage
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.label1 = new System.Windows.Forms.Label();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.bt_Biens = new System.Windows.Forms.Button();
            this.bt_Agent = new System.Windows.Forms.Button();
            this.bt_Acheteur = new System.Windows.Forms.Button();
            this.tabControl_Acheteur = new System.Windows.Forms.TabControl();
            this.tabPage1_Acheteur = new System.Windows.Forms.TabPage();
            this.tabPage2_Acheteur = new System.Windows.Forms.TabPage();
            this.tabControl_Agent = new System.Windows.Forms.TabControl();
            this.tabPage1_Agent = new System.Windows.Forms.TabPage();
            this.tabPage2_Agents = new System.Windows.Forms.TabPage();
            this.tabControl_Biens = new System.Windows.Forms.TabControl();
            this.tabPage1_Biens = new System.Windows.Forms.TabPage();
            this.tabPage2_Biens = new System.Windows.Forms.TabPage();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).BeginInit();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            this.tabControl_Acheteur.SuspendLayout();
            this.tabControl_Agent.SuspendLayout();
            this.tabControl_Biens.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainer1
            // 
            this.splitContainer1.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.FixedPanel = System.Windows.Forms.FixedPanel.Panel1;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Margin = new System.Windows.Forms.Padding(0);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.splitContainer1.Panel1.Controls.Add(this.label1);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.splitContainer1.Panel2.Controls.Add(this.splitContainer2);
            this.splitContainer1.Size = new System.Drawing.Size(1297, 627);
            this.splitContainer1.SplitterDistance = 25;
            this.splitContainer1.SplitterWidth = 1;
            this.splitContainer1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label1.ForeColor = System.Drawing.Color.Red;
            this.label1.Location = new System.Drawing.Point(1248, 6);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(306, 18);
            this.label1.TabIndex = 0;
            this.label1.Text = "Không có BIENS mới nào trong 2 ngày qua";
            // 
            // splitContainer2
            // 
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.Location = new System.Drawing.Point(0, 0);
            this.splitContainer2.Name = "splitContainer2";
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add(this.bt_Biens);
            this.splitContainer2.Panel1.Controls.Add(this.bt_Agent);
            this.splitContainer2.Panel1.Controls.Add(this.bt_Acheteur);
            this.splitContainer2.Panel1MinSize = 20;
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add(this.tabControl_Acheteur);
            this.splitContainer2.Panel2.Controls.Add(this.tabControl_Agent);
            this.splitContainer2.Panel2.Controls.Add(this.tabControl_Biens);
            this.splitContainer2.Size = new System.Drawing.Size(1297, 601);
            this.splitContainer2.SplitterDistance = 151;
            this.splitContainer2.SplitterWidth = 1;
            this.splitContainer2.TabIndex = 1;
            // 
            // bt_Biens
            // 
            this.bt_Biens.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.bt_Biens.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.bt_Biens.Location = new System.Drawing.Point(28, 60);
            this.bt_Biens.Name = "bt_Biens";
            this.bt_Biens.Size = new System.Drawing.Size(109, 41);
            this.bt_Biens.TabIndex = 0;
            this.bt_Biens.Text = "BIENS";
            this.bt_Biens.UseVisualStyleBackColor = true;
            this.bt_Biens.Click += new System.EventHandler(this.bt_Biens_Click);
            // 
            // bt_Agent
            // 
            this.bt_Agent.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.bt_Agent.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.bt_Agent.Location = new System.Drawing.Point(28, 220);
            this.bt_Agent.Name = "bt_Agent";
            this.bt_Agent.Size = new System.Drawing.Size(109, 41);
            this.bt_Agent.TabIndex = 0;
            this.bt_Agent.Text = "AGENT";
            this.bt_Agent.UseVisualStyleBackColor = true;
            this.bt_Agent.Click += new System.EventHandler(this.bt_Agent_Click);
            // 
            // bt_Acheteur
            // 
            this.bt_Acheteur.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.bt_Acheteur.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.bt_Acheteur.Location = new System.Drawing.Point(28, 140);
            this.bt_Acheteur.Name = "bt_Acheteur";
            this.bt_Acheteur.Size = new System.Drawing.Size(109, 41);
            this.bt_Acheteur.TabIndex = 0;
            this.bt_Acheteur.Text = "ACHETEUR";
            this.bt_Acheteur.UseVisualStyleBackColor = true;
            this.bt_Acheteur.Click += new System.EventHandler(this.bt_Acheteur_Click);
            // 
            // tabControl_Acheteur
            // 
            this.tabControl_Acheteur.Controls.Add(this.tabPage1_Acheteur);
            this.tabControl_Acheteur.Controls.Add(this.tabPage2_Acheteur);
            this.tabControl_Acheteur.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl_Acheteur.Font = new System.Drawing.Font("Arial", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.tabControl_Acheteur.Location = new System.Drawing.Point(0, 0);
            this.tabControl_Acheteur.Name = "tabControl_Acheteur";
            this.tabControl_Acheteur.SelectedIndex = 0;
            this.tabControl_Acheteur.Size = new System.Drawing.Size(1145, 601);
            this.tabControl_Acheteur.TabIndex = 0;
            this.tabControl_Acheteur.Visible = false;
            this.tabControl_Acheteur.SelectedIndexChanged += new System.EventHandler(this.tabControl_Acheteur_SelectedIndexChanged);
            // 
            // tabPage1_Acheteur
            // 
            this.tabPage1_Acheteur.Location = new System.Drawing.Point(4, 26);
            this.tabPage1_Acheteur.Name = "tabPage1_Acheteur";
            this.tabPage1_Acheteur.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1_Acheteur.Size = new System.Drawing.Size(1137, 571);
            this.tabPage1_Acheteur.TabIndex = 0;
            this.tabPage1_Acheteur.Text = "Fiche Souhait";
            this.tabPage1_Acheteur.UseVisualStyleBackColor = true;
            // 
            // tabPage2_Acheteur
            // 
            this.tabPage2_Acheteur.Location = new System.Drawing.Point(4, 26);
            this.tabPage2_Acheteur.Name = "tabPage2_Acheteur";
            this.tabPage2_Acheteur.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2_Acheteur.Size = new System.Drawing.Size(1137, 571);
            this.tabPage2_Acheteur.TabIndex = 1;
            this.tabPage2_Acheteur.Text = "Acheteur";
            this.tabPage2_Acheteur.UseVisualStyleBackColor = true;
            // 
            // tabControl_Agent
            // 
            this.tabControl_Agent.Controls.Add(this.tabPage1_Agent);
            this.tabControl_Agent.Controls.Add(this.tabPage2_Agents);
            this.tabControl_Agent.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl_Agent.Font = new System.Drawing.Font("Arial", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.tabControl_Agent.Location = new System.Drawing.Point(0, 0);
            this.tabControl_Agent.Name = "tabControl_Agent";
            this.tabControl_Agent.SelectedIndex = 0;
            this.tabControl_Agent.Size = new System.Drawing.Size(1145, 601);
            this.tabControl_Agent.TabIndex = 0;
            this.tabControl_Agent.Visible = false;
            this.tabControl_Agent.SelectedIndexChanged += new System.EventHandler(this.tabControl_Agent_SelectedIndexChanged);
            // 
            // tabPage1_Agent
            // 
            this.tabPage1_Agent.Location = new System.Drawing.Point(4, 26);
            this.tabPage1_Agent.Name = "tabPage1_Agent";
            this.tabPage1_Agent.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1_Agent.Size = new System.Drawing.Size(1137, 571);
            this.tabPage1_Agent.TabIndex = 0;
            this.tabPage1_Agent.Text = "Agent";
            this.tabPage1_Agent.UseVisualStyleBackColor = true;
            // 
            // tabPage2_Agents
            // 
            this.tabPage2_Agents.Location = new System.Drawing.Point(4, 26);
            this.tabPage2_Agents.Name = "tabPage2_Agents";
            this.tabPage2_Agents.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2_Agents.Size = new System.Drawing.Size(1137, 571);
            this.tabPage2_Agents.TabIndex = 1;
            this.tabPage2_Agents.Text = "Liste d\'Agents";
            this.tabPage2_Agents.UseVisualStyleBackColor = true;
            // 
            // tabControl_Biens
            // 
            this.tabControl_Biens.Controls.Add(this.tabPage1_Biens);
            this.tabControl_Biens.Controls.Add(this.tabPage2_Biens);
            this.tabControl_Biens.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl_Biens.Font = new System.Drawing.Font("Arial", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.tabControl_Biens.Location = new System.Drawing.Point(0, 0);
            this.tabControl_Biens.Name = "tabControl_Biens";
            this.tabControl_Biens.SelectedIndex = 0;
            this.tabControl_Biens.Size = new System.Drawing.Size(1145, 601);
            this.tabControl_Biens.SizeMode = System.Windows.Forms.TabSizeMode.FillToRight;
            this.tabControl_Biens.TabIndex = 0;
            this.tabControl_Biens.Visible = false;
            this.tabControl_Biens.SelectedIndexChanged += new System.EventHandler(this.tabControl_Biens_SelectedIndexChanged);
            // 
            // tabPage1_Biens
            // 
            this.tabPage1_Biens.Location = new System.Drawing.Point(4, 26);
            this.tabPage1_Biens.Name = "tabPage1_Biens";
            this.tabPage1_Biens.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1_Biens.Size = new System.Drawing.Size(1137, 571);
            this.tabPage1_Biens.TabIndex = 0;
            this.tabPage1_Biens.Text = "Fiche de description";
            this.tabPage1_Biens.UseVisualStyleBackColor = true;
            // 
            // tabPage2_Biens
            // 
            this.tabPage2_Biens.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabPage2_Biens.Location = new System.Drawing.Point(4, 26);
            this.tabPage2_Biens.Name = "tabPage2_Biens";
            this.tabPage2_Biens.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2_Biens.Size = new System.Drawing.Size(1137, 571);
            this.tabPage2_Biens.TabIndex = 1;
            this.tabPage2_Biens.Text = "Liste De Biens";
            this.tabPage2_Biens.UseVisualStyleBackColor = true;
            // 
            // timer1
            // 
            this.timer1.Interval = 1;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // MainPage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1297, 627);
            this.Controls.Add(this.splitContainer1);
            this.Name = "MainPage";
            this.Text = "MainPage";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).EndInit();
            this.splitContainer2.ResumeLayout(false);
            this.tabControl_Acheteur.ResumeLayout(false);
            this.tabControl_Agent.ResumeLayout(false);
            this.tabControl_Biens.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.Button bt_Agent;
        private System.Windows.Forms.Button bt_Acheteur;
        private System.Windows.Forms.Button bt_Biens;
        private System.Windows.Forms.TabControl tabControl_Biens;
        private System.Windows.Forms.TabPage tabPage1_Biens;
        private System.Windows.Forms.TabPage tabPage2_Biens;
        private System.Windows.Forms.TabControl tabControl_Acheteur;
        private System.Windows.Forms.TabPage tabPage1_Acheteur;
        private System.Windows.Forms.TabPage tabPage2_Acheteur;
        private System.Windows.Forms.TabControl tabControl_Agent;
        private System.Windows.Forms.TabPage tabPage1_Agent;
        private System.Windows.Forms.TabPage tabPage2_Agents;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label label1;
    }
}