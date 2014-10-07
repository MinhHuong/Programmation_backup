using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Drawing;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;

namespace Projet_ImmoRale.Tools
{
    public class Aide
    {
        public static Int32 parseInt(string num)
        {
            Int32 res;
            if (Int32.TryParse(num, out res))
                return res;
            else
                return 0;
        }

        public static float parseFloat(string num)
        {
            float res;
            if (float.TryParse(num, out res))
                return res;
            else
                return 0;
        }

        public static DateTime parseDate(string num)
        {
            DateTime res;
            if (DateTime.TryParse(num, out res))
                return res;
            else
                return DateTime.MinValue;
        }

        public static bool isNumber(string num)
        {
            Regex regex = new Regex("^[0-9]+$");
            return regex.IsMatch(num);
        }

        public static bool isEmail(string str)
        {
            Regex regex = new Regex(@"^(?("")("".+?(?<!\\)""@)|(([0-9a-z]((\.(?!\.))|[-!#\$%&'\*\+/=\?\^`\{\}\|~\w])*)(?<=[0-9a-z])@))" +
                @"(?(\[)(\[(\d{1,3}\.){3}\d{1,3}\])|(([0-9a-z][-\w]*[0-9a-z]*\.)+[a-z0-9][\-a-z0-9]{0,22}[a-z0-9]))$");
            return regex.IsMatch(str);
        }

        public static byte[] imageToByteArray(Image img)
        {
            using (var ms = new MemoryStream())
            {
                img.Save(ms, System.Drawing.Imaging.ImageFormat.Bmp);
                return ms.ToArray();
            }
        }

        public static Image byteArrayToImage(byte[] src)
        {
            using (var ms = new MemoryStream(src))
            {
                return Image.FromStream(ms);
            }
        }

        public static string byteArrayToString(byte[] src)
        {
            var str = System.Text.Encoding.Default.GetString(src);
            return str;
        }

        public static byte[] stringToByteArray(string src)
        {
            byte[] dest = new byte[src.Length * sizeof(char)];
            System.Buffer.BlockCopy(src.ToCharArray(), 0, dest, 0, dest.Length);
            return dest;
        }

        public static string getNameImage(string fullPath)
        {
            string[] donnees = fullPath.Split('\\');
            int index = donnees.Length;
            return donnees[index - 1];
        }

        public static string setPathImage(string nameImage)
        {
            string path = "..\\..\\..\\Images\\" + nameImage;
            return path;
        }
    }
}
