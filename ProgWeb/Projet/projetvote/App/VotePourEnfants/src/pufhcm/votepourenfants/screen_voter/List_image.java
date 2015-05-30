package pufhcm.votepourenfants.screen_voter;

import java.io.Serializable;

public class List_image implements Serializable {
	
	//dung bien static de bien nay hien huu suot chuong trinh, thay doi theo huong hinh nguoi bo phieu bo phieu roi hay chua
	//sau do cap nhat de hien nguoi nao da vote roi.... bang cach cho hinh nguoi do bien thanh trang den

	private static final long serialVersionUID = 1L;

	String speak = "Bonjour";

   public static List_image SharedInstance = null;

   /**
    * Get the shared instance of List_image used in this demo.
    * 
    * @return List_image
    */

   static public List_image getInstance () {
	   if (SharedInstance == null) 
		   SharedInstance = new List_image ();
	   return SharedInstance;
   }

   /**
    * Set the shared instance of List_image used in this demo.
    * 
    * @param tlist List_image
    * @return void
    */

   static public void setInstance (List_image tlist) {
	   SharedInstance = tlist;
   }



   /**
    * Constructer
    * 
    * @param sampleText String - text to be spoken for app
    * 
    */

   public List_image () {
   }

   /**
    * Get the total number of voter in the list.
    * 
    * @return int
    */


   public int getNumVoter () {
	   return Voter_information.Voter_names.length;
   }

   /**
    * Get the name of the nth voter in the list.
    * 
    * @param index int - index number for a topic
    * @return String
    */

   public String getName (int index) {
	   if (index >= Voter_information.Voter_names.length) return null;
	   return Voter_information.Voter_names [index];
   }

   /**
    * Get the image id of the nth voter in the list.
    * 
    * @param index int - index number for a image
    * @return int - id of the image
    */

   public int IndexImage (int index) { // chac bo, tai vi index day cung chinh la index, nhung rang buoc de khoi ra het man hinh
	   if (index >= Voter_information.Voter_names.length) return 0;
	   return Voter_information.ImageIds [index];
   }

   /**
    * Get the text for the nth voter in the list.
    * 
    * @param index int - index number for a topic
    * @return String
    */

   public String getTextSpeaking (int index) {
	   if (index >= Voter_information.Voter_names.length) return null;
	   return speak;
   }

}

