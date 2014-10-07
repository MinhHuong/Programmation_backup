namespace Projet_ImmoRale
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainPage));
            this.tc_MainPage = new System.Windows.Forms.TabControl();
            this.tp_accueil = new System.Windows.Forms.TabPage();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.llb_quit = new System.Windows.Forms.LinkLabel();
            this.llb_help = new System.Windows.Forms.LinkLabel();
            this.llb_about = new System.Windows.Forms.LinkLabel();
            this.pn_image = new System.Windows.Forms.Panel();
            this.tp_bien = new System.Windows.Forms.TabPage();
            this.listeBiens = new Projet_ImmoRale.FormDesign.ListeBiens();
            this.ficheBien = new Projet_ImmoRale.FicheBien();
            this.ts_biens = new System.Windows.Forms.ToolStrip();
            this.tsb_nouveauFiche = new System.Windows.Forms.ToolStripButton();
            this.tsb_saveFiche = new System.Windows.Forms.ToolStripButton();
            this.tsb_deleteFiche = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.tsb_findBien = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.tp_acheteur = new System.Windows.Forms.TabPage();
            this.tp_agent = new System.Windows.Forms.TabPage();
            this.listeAgents = new Projet_ImmoRale.FormDesign.ListeAgents();
            this.ficheAgent = new Projet_ImmoRale.FormDesign.FicheAgent();
            this.ts_agents = new System.Windows.Forms.ToolStrip();
            this.tsb_newAgent = new System.Windows.Forms.ToolStripButton();
            this.tsb_saveAgent = new System.Windows.Forms.ToolStripButton();
            this.tsb_deleteFicheAgent = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.tsb_findAgent = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.tc_MainPage.SuspendLayout();
            this.tp_accueil.SuspendLayout();
            this.tp_bien.SuspendLayout();
            this.ts_biens.SuspendLayout();
            this.tp_agent.SuspendLayout();
            this.ts_agents.SuspendLayout();
            this.SuspendLayout();
            // 
            // tc_MainPage
            // 
            this.tc_MainPage.Controls.Add(this.tp_accueil);
            this.tc_MainPage.Controls.Add(this.tp_bien);
            this.tc_MainPage.Controls.Add(this.tp_acheteur);
            this.tc_MainPage.Controls.Add(this.tp_agent);
            this.tc_MainPage.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tc_MainPage.Location = new System.Drawing.Point(0, 0);
            this.tc_MainPage.Name = "tc_MainPage";
            this.tc_MainPage.SelectedIndex = 0;
            this.tc_MainPage.Size = new System.Drawing.Size(782, 635);
            this.tc_MainPage.TabIndex = 0;
            // 
            // tp_accueil
            // 
            this.tp_accueil.Controls.Add(this.label3);
            this.tp_accueil.Controls.Add(this.label2);
            this.tp_accueil.Controls.Add(this.label1);
            this.tp_accueil.Controls.Add(this.llb_quit);
            this.tp_accueil.Controls.Add(this.llb_help);
            this.tp_accueil.Controls.Add(this.llb_about);
            this.tp_accueil.Controls.Add(this.pn_image);
            this.tp_accueil.Location = new System.Drawing.Point(4, 25);
            this.tp_accueil.Name = "tp_accueil";
            this.tp_accueil.Padding = new System.Windows.Forms.Padding(3);
            this.tp_accueil.Size = new System.Drawing.Size(774, 606);
            this.tp_accueil.TabIndex = 0;
            this.tp_accueil.Text = "Accueil";
            this.tp_accueil.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.Image = ((System.Drawing.Image)(resources.GetObject("label3.Image")));
            this.label3.Location = new System.Drawing.Point(481, 266);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(30, 30);
            this.label3.TabIndex = 6;
            // 
            // label2
            // 
            this.label2.Image = ((System.Drawing.Image)(resources.GetObject("label2.Image")));
            this.label2.Location = new System.Drawing.Point(481, 188);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(30, 30);
            this.label2.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.Image = ((System.Drawing.Image)(resources.GetObject("label1.Image")));
            this.label1.Location = new System.Drawing.Point(481, 105);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(30, 30);
            this.label1.TabIndex = 4;
            // 
            // llb_quit
            // 
            this.llb_quit.Font = new System.Drawing.Font("Candara", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.llb_quit.LinkBehavior = System.Windows.Forms.LinkBehavior.HoverUnderline;
            this.llb_quit.Location = new System.Drawing.Point(528, 266);
            this.llb_quit.Name = "llb_quit";
            this.llb_quit.Size = new System.Drawing.Size(74, 30);
            this.llb_quit.TabIndex = 3;
            this.llb_quit.TabStop = true;
            this.llb_quit.Text = "Quitter";
            this.llb_quit.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.llb_quit.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.llb_quit_LinkClicked);
            // 
            // llb_help
            // 
            this.llb_help.AutoSize = true;
            this.llb_help.Font = new System.Drawing.Font("Candara", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.llb_help.LinkBehavior = System.Windows.Forms.LinkBehavior.HoverUnderline;
            this.llb_help.Location = new System.Drawing.Point(528, 194);
            this.llb_help.Name = "llb_help";
            this.llb_help.Size = new System.Drawing.Size(47, 24);
            this.llb_help.TabIndex = 2;
            this.llb_help.TabStop = true;
            this.llb_help.Text = "Aide";
            this.llb_help.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // llb_about
            // 
            this.llb_about.Font = new System.Drawing.Font("Candara", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.llb_about.LinkBehavior = System.Windows.Forms.LinkBehavior.HoverUnderline;
            this.llb_about.LinkColor = System.Drawing.Color.MediumBlue;
            this.llb_about.Location = new System.Drawing.Point(517, 105);
            this.llb_about.Name = "llb_about";
            this.llb_about.Size = new System.Drawing.Size(125, 30);
            this.llb_about.TabIndex = 1;
            this.llb_about.TabStop = true;
            this.llb_about.Text = "À  propos...";
            this.llb_about.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // pn_image
            // 
            this.pn_image.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pn_image.BackgroundImage")));
            this.pn_image.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pn_image.Location = new System.Drawing.Point(56, 54);
            this.pn_image.Name = "pn_image";
            this.pn_image.Size = new System.Drawing.Size(300, 288);
            this.pn_image.TabIndex = 0;
            // 
            // tp_bien
            // 
            this.tp_bien.Controls.Add(this.listeBiens);
            this.tp_bien.Controls.Add(this.ficheBien);
            this.tp_bien.Controls.Add(this.ts_biens);
            this.tp_bien.Location = new System.Drawing.Point(4, 25);
            this.tp_bien.Name = "tp_bien";
            this.tp_bien.Padding = new System.Windows.Forms.Padding(3);
            this.tp_bien.Size = new System.Drawing.Size(774, 606);
            this.tp_bien.TabIndex = 1;
            this.tp_bien.Text = "Biens";
            this.tp_bien.UseVisualStyleBackColor = true;
            // 
            // listeBiens
            // 
            this.listeBiens.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.listeBiens.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listeBiens.Location = new System.Drawing.Point(3, 69);
            this.listeBiens.Name = "listeBiens";
            this.listeBiens.Size = new System.Drawing.Size(768, 534);
            this.listeBiens.TabIndex = 2;
            // 
            // ficheBien
            // 
            this.ficheBien.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.ficheBien.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.ficheBien.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ficheBien.Location = new System.Drawing.Point(3, 69);
            this.ficheBien.Name = "ficheBien";
            this.ficheBien.Size = new System.Drawing.Size(768, 534);
            this.ficheBien.TabIndex = 1;
            // 
            // ts_biens
            // 
            this.ts_biens.AutoSize = false;
            this.ts_biens.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsb_nouveauFiche,
            this.tsb_saveFiche,
            this.tsb_deleteFiche,
            this.toolStripSeparator1,
            this.tsb_findBien,
            this.toolStripSeparator2});
            this.ts_biens.Location = new System.Drawing.Point(3, 3);
            this.ts_biens.Name = "ts_biens";
            this.ts_biens.Size = new System.Drawing.Size(768, 66);
            this.ts_biens.TabIndex = 0;
            this.ts_biens.Text = "toolStrip1";
            // 
            // tsb_nouveauFiche
            // 
            this.tsb_nouveauFiche.AutoSize = false;
            this.tsb_nouveauFiche.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.tsb_nouveauFiche.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsb_nouveauFiche.Image = ((System.Drawing.Image)(resources.GetObject("tsb_nouveauFiche.Image")));
            this.tsb_nouveauFiche.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsb_nouveauFiche.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsb_nouveauFiche.Name = "tsb_nouveauFiche";
            this.tsb_nouveauFiche.Size = new System.Drawing.Size(63, 63);
            this.tsb_nouveauFiche.Text = "Nouvelle fiche";
            this.tsb_nouveauFiche.Click += new System.EventHandler(this.tsb_nouveauFiche_Click);
            // 
            // tsb_saveFiche
            // 
            this.tsb_saveFiche.AutoSize = false;
            this.tsb_saveFiche.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.tsb_saveFiche.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsb_saveFiche.Image = ((System.Drawing.Image)(resources.GetObject("tsb_saveFiche.Image")));
            this.tsb_saveFiche.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsb_saveFiche.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsb_saveFiche.Name = "tsb_saveFiche";
            this.tsb_saveFiche.Size = new System.Drawing.Size(63, 63);
            this.tsb_saveFiche.Text = "Sauvegarder cette fiche";
            // 
            // tsb_deleteFiche
            // 
            this.tsb_deleteFiche.AutoSize = false;
            this.tsb_deleteFiche.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.tsb_deleteFiche.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsb_deleteFiche.Image = ((System.Drawing.Image)(resources.GetObject("tsb_deleteFiche.Image")));
            this.tsb_deleteFiche.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsb_deleteFiche.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsb_deleteFiche.Name = "tsb_deleteFiche";
            this.tsb_deleteFiche.Size = new System.Drawing.Size(63, 63);
            this.tsb_deleteFiche.Text = "Annuler cette fiche";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 66);
            // 
            // tsb_findBien
            // 
            this.tsb_findBien.AutoSize = false;
            this.tsb_findBien.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.tsb_findBien.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsb_findBien.Image = ((System.Drawing.Image)(resources.GetObject("tsb_findBien.Image")));
            this.tsb_findBien.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsb_findBien.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsb_findBien.Name = "tsb_findBien";
            this.tsb_findBien.Size = new System.Drawing.Size(63, 63);
            this.tsb_findBien.Text = "Chercher un bien";
            this.tsb_findBien.Click += new System.EventHandler(this.tsb_findBien_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 66);
            // 
            // tp_acheteur
            // 
            this.tp_acheteur.Location = new System.Drawing.Point(4, 25);
            this.tp_acheteur.Name = "tp_acheteur";
            this.tp_acheteur.Padding = new System.Windows.Forms.Padding(3);
            this.tp_acheteur.Size = new System.Drawing.Size(774, 606);
            this.tp_acheteur.TabIndex = 2;
            this.tp_acheteur.Text = "Acheteurs";
            this.tp_acheteur.UseVisualStyleBackColor = true;
            // 
            // tp_agent
            // 
            this.tp_agent.Controls.Add(this.listeAgents);
            this.tp_agent.Controls.Add(this.ficheAgent);
            this.tp_agent.Controls.Add(this.ts_agents);
            this.tp_agent.Location = new System.Drawing.Point(4, 25);
            this.tp_agent.Name = "tp_agent";
            this.tp_agent.Padding = new System.Windows.Forms.Padding(3);
            this.tp_agent.Size = new System.Drawing.Size(774, 606);
            this.tp_agent.TabIndex = 3;
            this.tp_agent.Text = "Agents";
            this.tp_agent.UseVisualStyleBackColor = true;
            // 
            // listeAgents
            // 
            this.listeAgents.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.listeAgents.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listeAgents.Location = new System.Drawing.Point(3, 69);
            this.listeAgents.Name = "listeAgents";
            this.listeAgents.Size = new System.Drawing.Size(768, 534);
            this.listeAgents.TabIndex = 2;
            this.listeAgents.AgentModifiedEvent += new Projet_ImmoRale.FormDesign.ListeAgents.AgentModified(this.AgentModified_MainPage);
            // 
            // ficheAgent
            // 
            this.ficheAgent.BackColor = System.Drawing.SystemColors.Control;
            this.ficheAgent.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ficheAgent.Location = new System.Drawing.Point(3, 69);
            this.ficheAgent.Name = "ficheAgent";
            this.ficheAgent.Size = new System.Drawing.Size(768, 534);
            this.ficheAgent.TabIndex = 1;
            this.ficheAgent.Valide = false;
            // 
            // ts_agents
            // 
            this.ts_agents.AutoSize = false;
            this.ts_agents.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsb_newAgent,
            this.tsb_saveAgent,
            this.tsb_deleteFicheAgent,
            this.toolStripSeparator3,
            this.tsb_findAgent,
            this.toolStripSeparator4});
            this.ts_agents.Location = new System.Drawing.Point(3, 3);
            this.ts_agents.Name = "ts_agents";
            this.ts_agents.Size = new System.Drawing.Size(768, 66);
            this.ts_agents.TabIndex = 0;
            this.ts_agents.Text = "toolStrip1";
            // 
            // tsb_newAgent
            // 
            this.tsb_newAgent.AutoSize = false;
            this.tsb_newAgent.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsb_newAgent.Image = ((System.Drawing.Image)(resources.GetObject("tsb_newAgent.Image")));
            this.tsb_newAgent.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsb_newAgent.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsb_newAgent.Name = "tsb_newAgent";
            this.tsb_newAgent.Size = new System.Drawing.Size(63, 63);
            this.tsb_newAgent.Text = "Ajouter un nouvel agent";
            this.tsb_newAgent.Click += new System.EventHandler(this.tsb_newAgent_Click);
            // 
            // tsb_saveAgent
            // 
            this.tsb_saveAgent.AutoSize = false;
            this.tsb_saveAgent.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsb_saveAgent.Image = ((System.Drawing.Image)(resources.GetObject("tsb_saveAgent.Image")));
            this.tsb_saveAgent.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsb_saveAgent.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsb_saveAgent.Name = "tsb_saveAgent";
            this.tsb_saveAgent.Size = new System.Drawing.Size(63, 63);
            this.tsb_saveAgent.Text = "toolStripButton1";
            this.tsb_saveAgent.Click += new System.EventHandler(this.tsb_saveAgent_Click);
            // 
            // tsb_deleteFicheAgent
            // 
            this.tsb_deleteFicheAgent.AutoSize = false;
            this.tsb_deleteFicheAgent.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsb_deleteFicheAgent.Image = ((System.Drawing.Image)(resources.GetObject("tsb_deleteFicheAgent.Image")));
            this.tsb_deleteFicheAgent.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsb_deleteFicheAgent.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsb_deleteFicheAgent.Name = "tsb_deleteFicheAgent";
            this.tsb_deleteFicheAgent.Size = new System.Drawing.Size(63, 63);
            this.tsb_deleteFicheAgent.Text = "Annuler cette fiche";
            this.tsb_deleteFicheAgent.Click += new System.EventHandler(this.tsb_deleteFicheAgent_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(6, 66);
            // 
            // tsb_findAgent
            // 
            this.tsb_findAgent.AutoSize = false;
            this.tsb_findAgent.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsb_findAgent.Image = ((System.Drawing.Image)(resources.GetObject("tsb_findAgent.Image")));
            this.tsb_findAgent.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsb_findAgent.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsb_findAgent.Name = "tsb_findAgent";
            this.tsb_findAgent.Size = new System.Drawing.Size(63, 63);
            this.tsb_findAgent.Text = "toolStripButton1";
            this.tsb_findAgent.Click += new System.EventHandler(this.tsb_findAgent_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(6, 66);
            // 
            // MainPage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(782, 635);
            this.Controls.Add(this.tc_MainPage);
            this.DoubleBuffered = true;
            this.Name = "MainPage";
            this.Text = "Logiciel à gestion Immo Rale";
            this.tc_MainPage.ResumeLayout(false);
            this.tp_accueil.ResumeLayout(false);
            this.tp_accueil.PerformLayout();
            this.tp_bien.ResumeLayout(false);
            this.ts_biens.ResumeLayout(false);
            this.ts_biens.PerformLayout();
            this.tp_agent.ResumeLayout(false);
            this.ts_agents.ResumeLayout(false);
            this.ts_agents.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tc_MainPage;
        private System.Windows.Forms.TabPage tp_bien;
        private System.Windows.Forms.TabPage tp_acheteur;
        private System.Windows.Forms.TabPage tp_agent;
        private System.Windows.Forms.TabPage tp_accueil;
        private System.Windows.Forms.ToolStrip ts_biens;
        private System.Windows.Forms.ToolStripButton tsb_nouveauFiche;
        private System.Windows.Forms.ToolStripButton tsb_saveFiche;
        private System.Windows.Forms.ToolStripButton tsb_deleteFiche;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripButton tsb_findBien;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStrip ts_agents;
        private System.Windows.Forms.ToolStripButton tsb_newAgent;
        private System.Windows.Forms.ToolStripButton tsb_saveAgent;
        private System.Windows.Forms.ToolStripButton tsb_deleteFicheAgent;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripButton tsb_findAgent;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.LinkLabel llb_quit;
        private System.Windows.Forms.LinkLabel llb_help;
        private System.Windows.Forms.LinkLabel llb_about;
        private System.Windows.Forms.Panel pn_image;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private FicheBien ficheBien;
        private FormDesign.ListeBiens listeBiens;
        private FormDesign.FicheAgent ficheAgent;
        private FormDesign.ListeAgents listeAgents;
    }
}

