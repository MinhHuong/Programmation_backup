package pufhcm.votepourenfants;



import pufhcm.votepourenfants.util.SystemUiHider;
import android.annotation.TargetApi;
import android.app.Activity;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.view.MotionEvent;
import android.view.View;



/**
 * An example full-screen activity that shows and hides the system UI (i.e.
 * status bar and navigation/system bar) with user interaction.
 *
 * @see SystemUiHider
 */
public class Waiting_screen extends Activity {


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		setContentView(R.layout.activity_waiting_screen);
		
		//Resources res = getResources ();// doc resource de su dung sau nay khoi viet dai dong
		//ImageView image_view = (ImageView) findViewById(R.id.fullscreen_content);


		final View contentView = findViewById(R.id.waiting);  // event click tren hinh nen luc waiting

		// Set up an instance of SystemUiHider to control the system UI for
		// this activity.
		

		// Set up the user interaction to manually show or hide the system UI.
		contentView.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View view) {
				
				//Create an Intent to start the ImageViewActivity
				Intent intent = new Intent(Waiting_screen.this, Voter_selecter.class);
				
				// Add the ID of the thumbnail to display as an Intent Extra
				//intent.putExtra(EXTRA_RES_ID, (int) id);
				
				// Start the ImageViewActivity
				startActivity(intent);
				finish(); // xoa luon trang nay, de khong phai quay ve lai trang nay nua
				//if (TOGGLE_ON_CLICK) {
					//mSystemUiHider.toggle();
				//} else {
				//	mSystemUiHider.show();
				//}
			}
		});

		// Upon interacting with UI controls, delay any scheduled hide()
		// operations to prevent the jarring behavior of controls going away
		// while interacting with the UI.
		//findViewById(R.id.dummy_button).setOnTouchListener(
				//mDelayHideTouchListener);
		
		//ImageView imgView = (ImageView) findViewById(R.id.fullscreen_content);
		// Set the Image in ImageView after decoding the String
		//imgView.setImageBitmap(BitmapFactory
				//.decodeFile(imgDecodableString));
	}




}
