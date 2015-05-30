package pufhcm.votepourenfants;

import java.util.Locale;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.speech.tts.TextToSpeech;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.GridLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Toast;
import android.R.drawable;;

public class Resultat_screen extends Activity {
	int value0;
	int value1;
	int value2;
	int value3;
	TextToSpeech tts;
	

/**
 * onCreate 
 * Create a set of views from a FragmentPagerAdapter object.
 * Arrange for those views to be displayed by a ViewPager view.
 */

@Override protected void onCreate(Bundle savedInstanceState) {
   super.onCreate(savedInstanceState);
   Intent intent = getIntent();
   value0 = intent.getIntExtra("0", 0);
   value1 = intent.getIntExtra("1", 0);
   value2 = intent.getIntExtra("2", 0);
   value3 = intent.getIntExtra("3", 0);
   /*if (savedInstanceState != null) {
	   ArrayList<Integer> arr_tmp = savedInstanceState.getIntegerArrayList(KEY_TICK_VALUE);
	   array= arr_tmp;
	   }
   else {
	   for (int i = 0; i < Voter_information.ImageIds.length; i++)
		   array.add(1);
   }*/
   setContentView(R.layout.resultat);
   
   tts = new TextToSpeech(this, new TextToSpeech.OnInitListener() {

       @Override
       public void onInit(int status) {
           // TODO Auto-generated method stub
    	   if (status == TextToSpeech.SUCCESS) {
    	        // Setting speech language
    	        int result = tts.setLanguage(Locale.FRENCH);
    	        // If your device doesn't support language you set above
    	        if (result == TextToSpeech.LANG_MISSING_DATA
    	                || result == TextToSpeech.LANG_NOT_SUPPORTED) {
    	            // Cook simple toast message with message
    	            Toast.makeText(getApplicationContext(), "Language not supported",
    	                    Toast.LENGTH_LONG).show();
    	            Log.e("TTS", "Language is not supported");
    	        }
    	        // Enable the button - It was disabled in main.xml (Go back and
    	        // Check it)
    	        else {
    	        	
    	        	//tts.speak("Appuyer un clic long sur ton image, S'il te plaît", TextToSpeech.QUEUE_FLUSH, null);
    	        }
    	        // TTS is not initialized properly
    	    } else {
    	        //Toast.makeText(this, "TTS Initilization Failed", Toast.LENGTH_LONG)  .show();
    	        Log.e("TTS", "Initilization Failed");
    	    }
       }
   });
   
   GridLayout gl1 = (GridLayout)findViewById(R.id.gridLayout1);
   setupGridLayout(gl1, value0, 1);
   GridLayout gl2 = (GridLayout)findViewById(R.id.gridLayout2);
   setupGridLayout(gl2, value1, 2);
   GridLayout gl3 = (GridLayout)findViewById(R.id.gridLayout3);
   setupGridLayout(gl3, value2, 3);
   GridLayout gl4 = (GridLayout)findViewById(R.id.gridLayout4);
   setupGridLayout(gl4, value3, 4);
   ImageView img1 = (ImageView) findViewById(R.id.imageView1);
   img1.setOnClickListener(new OnClickListener() {
	   public void onClick(View v) {
           speaknumber (value0);
         }
       });
   ImageView img2 = (ImageView) findViewById(R.id.imageView2);
   img2.setOnClickListener(new OnClickListener() {
	   public void onClick(View v) {
		   speaknumber (value1);
         }
       });
   ImageView img3 = (ImageView) findViewById(R.id.imageView3);
   img3.setOnClickListener(new OnClickListener() {
	   public void onClick(View v) {
		   speaknumber (value2);
         }
       });
   ImageView img4 = (ImageView) findViewById(R.id.imageView4);
   img4.setOnClickListener(new OnClickListener() {
	   public void onClick(View v) {
		   speaknumber (value3);
         }
       });
}

private void setupGridLayout(GridLayout gl, int value, int index) {
	for (int i = 0; i<value; i++){
		if(index == 1)
			gl.addView(getImageView(R.drawable.color1));
		else if (index ==2)
			gl.addView(getImageView(R.drawable.color2));
		else if (index ==3)
			gl.addView(getImageView(R.drawable.color3));
		else
			gl.addView(getImageView(R.drawable.color4));
	}

   
}
private ImageView getImageView(int resource) {
   ImageView iv = new ImageView(this);
   GridLayout.LayoutParams layoutParams = new GridLayout.LayoutParams();
   
   iv.setLayoutParams(layoutParams);
   iv.setBackgroundResource(resource);
  // iv.set
   //iv.setPaddingRelative(10, 10, 10, 10);
   ///iv.setMaxWidth(50);
  // iv.setMaxHeight(50);
  // android:background="@color/background"
   return iv;
}

protected void speaknumber(int i) {
	
	String speak = String.valueOf(i);

    tts.speak(speak, TextToSpeech.QUEUE_FLUSH, null);

	
}





}
