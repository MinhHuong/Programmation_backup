package pufhcm.votepourenfants;

import java.util.Locale;

import pufhcm.votepourenfants.screen_voter.Voter_information;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.speech.tts.TextToSpeech;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageView;
import android.widget.Toast;


public class Vote_screen extends Activity {
	TextToSpeech tts; // for speak one sentence
	String name; // name of the voter
	int index; //position of the voter in the voter list

	

	/**
	 * onCreate 
	 * Create a set of views from a FragmentPagerAdapter object.
	 * Arrange for those views to be displayed by a ViewPager view.
	 */

	@Override 
	protected void onCreate(Bundle savedInstanceState) {
	   super.onCreate(savedInstanceState);
	   setContentView(R.layout.vote_item);
	   
	   
	   Intent intent = getIntent();
	   index = intent.getIntExtra("index", 0);
	   name = Voter_information.Voter_names [index];
	   tts = new TextToSpeech(this, new TextToSpeech.OnInitListener() {

		@Override
	       public void onInit(int status) {
	    	   if (status == TextToSpeech.SUCCESS) {
	    	        // Setting speech language
	    	        int result = tts.setLanguage(Locale.FRENCH);
	    	        // If your device doesn't support language you set above
	    	        if (result == TextToSpeech.LANG_MISSING_DATA  || result == TextToSpeech.LANG_NOT_SUPPORTED) {
	    	            // Cook simple toast message with message
	    	            Toast.makeText(getApplicationContext(), "Language not supported", Toast.LENGTH_LONG).show();
	    	            Log.e("TTS", "Language is not supported");
	    	        }
	    	        else {
	    	        	tts.speak("Bonjour " + name, TextToSpeech.QUEUE_FLUSH, null);
	    	        	//tts.speak("Appuyer un clic long sur ton image, S'il te plaît", TextToSpeech.QUEUE_FLUSH, null);
	    	        }
	    	        // TTS is not initialized properly
	    	    } else {
	    	        //Toast.makeText(this, "TTS Initilization Failed", Toast.LENGTH_LONG)  .show();
	    	        Log.e("TTS", "Initilization Failed");
	    	    }
	       }
	   });
	   //setup image item for vote
	   ImageView img1 = (ImageView) findViewById(R.id.imageView1);
	   img1.setOnClickListener(new OnClickListener() {
		   public void onClick(View v) {
               showImage (0);
             }
           });
	   ImageView img2 = (ImageView) findViewById(R.id.imageView2);
	   img2.setOnClickListener(new OnClickListener() {
		   public void onClick(View v) {
               showImage (1);
             }
           });
	   ImageView img3 = (ImageView) findViewById(R.id.imageView3);
	   img3.setOnClickListener(new OnClickListener() {
		   public void onClick(View v) {
               showImage (2);
             }
           });
	   ImageView img4 = (ImageView) findViewById(R.id.imageView4);
	   img4.setOnClickListener(new OnClickListener() {
		   public void onClick(View v) {
               showImage (3);
             }
           });
	    }

	protected void showImage(int i) {
		Intent intent = new Intent();
	    intent.putExtra("ordinal_number", i);
	    
	    setResult(RESULT_OK, intent);
	    
	    tts.speak("Merci et au revoir " + name, TextToSpeech.QUEUE_FLUSH, null);
	    finish();
		
	}
	/* When you dont chose anything but press BACK button, the voter won't be disable
	 * @see android.app.Activity#onBackPressed()
	 */
	@Override
    public void onBackPressed()
    {
		Intent intent = new Intent();
	    intent.putExtra("index", index);
	    
         setResult(RESULT_CANCELED, intent);
         
         super.onBackPressed();
    }




}
