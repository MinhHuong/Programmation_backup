namespace Projet_ImmoRale.FormDesign
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
            this.bt_findAgent = new System.Windows.Forms.Button();
            this.cbb_AgenceLocale = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.lv_Agent = new System.Windows.Forms.ListView();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
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
            this.splitContainer1.Panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.splitContainer1.Panel1.Controls.Add(this.bt_findAgent);
            this.splitContainer1.Panel1.Controls.Add(this.cbb_AgenceLocale);
            this.splitContainer1.Panel1.Controls.Add(this.label1);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.lv_Agent);
            this.splitContainer1.Size = new System.Drawing.Size(764, 458);
            this.splitContainer1.SplitterDistance = 95;
            this.splitContainer1.TabIndex = 0;
            // 
            // bt_findAgent
            // 
            this.bt_findAgent.Font = new System.Drawing.Font("Candara", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bt_findAgent.Location = new System.Drawing.Point(545, 31);
            this.bt_findAgent.Name = "bt_findAgent";
            this.bt_findAgent.Size = new System.Drawing.Size(134, 35);
            this.bt_findAgent.TabIndex = 2;
            this.bt_findAgent.Text = "Chercher";
            this.bt_findAgent.UseVisualStyleBackColor = true;
            this.bt_findAgent.Click += new System.EventHandler(this.bt_findAgent_Click);
            // 
            // cbb_AgenceLocale
            // 
            this.cbb_AgenceLocale.FormattingEnabled = true;
            this.cbb_AgenceLocale.Location = new System.Drawing.Point(234, 39);
            this.cbb_AgenceLocale.Name = "cbb_AgenceLocale";
            this.cbb_AgenceLocale.Size = new System.Drawing.Size(166, 24);
            this.cbb_AgenceLocale.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(116, 42);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(97, 17);
            this.label1.TabIndex = 0;
            this.label1.Text = "Agence locale";
            // 
            // lv_Agent
            // 
            this.lv_Agent.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lv_Agent.FullRowSelect = true;
            this.lv_Agent.Location = new System.Drawing.Point(0, 0);
            this.lv_Agent.Name = "lv_Agent";
            this.lv_Agent.Size = new System.Drawing.Size(764, 359);
            this.lv_Agent.TabIndex = 0;
            this.lv_Agent.UseCompatibleStateImageBehavior = false;
            this.lv_Agent.MouseDown += new System.Windows.Forms.MouseEventHandler(this.MouseDown_ListView);
            // 
            // ListeAgents
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Controls.Add(this.splitContainer1);
            this.DoubleBuffered = true;
            this.Name = "ListeAgents";
            this.Size = new System.Drawing.Size(764, 458);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.Button bt_findAgent;
        private System.Windows.Forms.ComboBox cbb_AgenceLocale;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ListView lv_Agent;
    }
}
