using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Projet_ImmoRale.Tools;

namespace Projet_ImmoRale.Objets
{
    public class Bien
    {
        #region attributs
        private Guid id = Guid.Empty;
        private string nomVendeur;
        private float surfaceHabitable;
        private float surfaceParcelle;
        private string typeHabitation;
        private int nbPieces;
        private int nbChambres;
        private int nbSDBain;
        private string avecGarage;
        private string avecCave;
        private float prixVenteSouhaite;
        private string adresseBien;
        private string dateMiseEnVente;
        private string prixVenteReel;
        private string dateVenteReel;
        private string commentaire;
        private string statutBien;
        private string idAcheteur;
        private string idVendeur;
        #endregion

        #region propriétés
        public Guid ID
        {
            get { return id; }
            set { id = value; }
        }

        public float SurfaceHabitable
        {
            get { return surfaceHabitable; }
            set { surfaceHabitable = value; }
        }

        public float SurfaceParcelle
        {
            get { return surfaceParcelle; }
            set { surfaceParcelle = value; }
        }

        public string TypeHabitation
        {
            get { return typeHabitation; }
            set { typeHabitation = value; }
        }

        public int NombrePieces
        {
            get { return nbPieces; }
            set { nbPieces = value; }
        }

        public int NombreChambres
        {
            get { return nbChambres; }
            set { nbChambres = value; }
        }

        public int NombreSDBain
        {
            get { return nbSDBain; }
            set { nbSDBain = value; }
        }

        public float PrixDeVenteSouhaite
        {
            get { return prixVenteSouhaite; }
            set { prixVenteSouhaite = value; }
        }

        private string AdresseBien
        {
            get { return adresseBien; }
            set { adresseBien = value; }
        }

        public string DateMiseEnVente
        {
            get { return dateMiseEnVente; }
            set { dateMiseEnVente = value; }
        }

        public string Commentaire
        {
            get { return commentaire; }
            set { commentaire = value; }
        }

        public string StatutBien
        {
            get { return statutBien; }
            set { statutBien = value; }
        }
        #endregion

        #region méthodes

        #endregion
    }
}
