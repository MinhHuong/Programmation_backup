using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SQLite;
using System.Data.Common;
using System.Data;

namespace Immo_Rale.DB
{

    public class DbManager
    {
        public static string DATE_FORMAT = "yyyy-MM-dd HH:mm";

        private DbManager() { }

        private static SQLiteConnection connection;

        static void OpenConnection(string fileName)
        {
            try
            {
                if (connection == null)
                {
                    connection = new SQLiteConnection();
                    connection.ConnectionString = new DbConnectionStringBuilder()
                    {
                        {"Data Source", fileName},
                        {"Version", "3"}
                    }.ConnectionString;
                }

                connection.Open();
            }
            catch (SQLiteException ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }

        static void CloseConnection()
        {
            if (connection != null)
                connection.Close();
        }

        private static String extractWhereClause(string where)
        {
            string res = "1=1";
            if (where.Trim() != String.Empty)
                res += " AND " + where;

            return res;
        }

        private static String extractFields(string[] columns)
        {
            string res = "";
            foreach (string field in columns)
            {
                res += field + ",";
            }

            return res.Substring(0, res.Length - 1);
        }

        private static String extractAssignment(string[] columns, string[] values)
        {
            string res = "";
            for (int i = 0; i < columns.Length; i++)
            {
                res += columns[i] + "=" + values[i] + ",";
            }
            return res.Substring(0, res.Length - 1);
        }

        public static Dictionary<String, Object> getFirst(string fileName, string tableName, string where)
        {
            try
            {
                OpenConnection(fileName);

                Dictionary<String, Object> res = null;

                string query = String.Format("SELECT * FROM {0} WHERE {1} ORDER BY ID LIMIT 1;", tableName, extractWhereClause(where));

                using (SQLiteDataAdapter da = new SQLiteDataAdapter(query, connection))
                {
                    DataSet ds = new DataSet();
                    da.Fill(ds, tableName);
                    DataTable dt = ds.Tables[tableName];

                    res = new Dictionary<string, object>();

                    foreach (DataRow row in dt.Rows)
                    {
                        foreach (DataColumn col in dt.Columns)
                        {
                            res.Add(col.ColumnName.ToLower(), row[col]);
                        }
                    }
                }

                return res;
            }
            catch (SQLiteException ex)
            {
                return null;
            }
            finally
            {
                CloseConnection();
            }
        }

        public static List<Dictionary<String, Object>> getList(string fileName, string tableName, string where)
        {
            try
            {
                OpenConnection(fileName);

                List<Dictionary<String, Object>> res = null;

                string query = String.Format("SELECT * FROM {0} WHERE {1};", tableName, extractWhereClause(where));

                using (SQLiteDataAdapter da = new SQLiteDataAdapter(query, connection))
                {
                    DataSet ds = new DataSet();
                    da.Fill(ds, tableName);
                    DataTable dt = ds.Tables[tableName];

                    res = new List<Dictionary<string, object>>();

                    foreach (DataRow row in dt.Rows)
                    {
                        Dictionary<string, object> entry = new Dictionary<string, object>();
                        foreach (DataColumn col in dt.Columns)
                        {
                            entry.Add(col.ColumnName.ToLower(), row[col]);
                        }
                        res.Add(entry);
                    }
                }

                return res;
            }
            catch (SQLiteException ex)
            {
                return null;
            }
            finally
            {
                CloseConnection();
            }
        }

        public static Boolean insert(string fileName, string tableName, string[] columns, string[] values)
        {
            try
            {
                OpenConnection(fileName);

                string query = String.Format("INSERT INTO {0} ({1}) VALUES ({2});", tableName, extractFields(columns), extractFields(values));

                int res = 0;
                using (SQLiteCommand cmd = new SQLiteCommand(query, connection))
                {
                    res = cmd.ExecuteNonQuery();
                }

                return res > 0;
            }
            catch (SQLiteException ex)
            {
                return false;
            }
            finally
            {
                CloseConnection();
            }
        }

        public static Boolean update(string fileName, string tableName, string[] columns, string[] values, string where)
        {
            try
            {
                OpenConnection(fileName);

                string query = String.Format("UPDATE {0} SET {1} WHERE {2};", tableName, extractAssignment(columns, values), extractWhereClause(where));

                int res = 0;
                using (SQLiteCommand cmd = new SQLiteCommand(query, connection))
                {
                    res = cmd.ExecuteNonQuery();
                }

                return res > 0;
            }
            catch (SQLiteException ex)
            {
                return false;
            }
            finally
            {
                CloseConnection();
            }

        }

        public static Boolean delete(string fileName, string tableName, string where)
        {
            try
            {
                OpenConnection(fileName);

                string query = String.Format("DELETE FROM {0} WHERE {1};", tableName, extractWhereClause(where));

                int res = 0;
                using (SQLiteCommand cmd = new SQLiteCommand(connection))
                {
                    cmd.CommandText = query;
                    res = cmd.ExecuteNonQuery();
                }

                return res > 0;
            }
            catch (SQLiteException ex)
            {
                return false;
            }
            finally
            {
                CloseConnection();
            }
        }

    }
}
