using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Immo_Rale.Tools
{
    class Aide
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
    }
}
