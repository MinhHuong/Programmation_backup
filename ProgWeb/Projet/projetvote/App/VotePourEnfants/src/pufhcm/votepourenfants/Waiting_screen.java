package pufhcm.votepourenfants;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;


/**
 * @author Sa Doa Tien Sinh
 * Create the first screen of the application
 */
public class Waiting_screen extends Activity {


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		setContentView(R.layout.activity_waiting_screen);

		final View contentView = findViewById(R.id.waiting);  // event click tren hinh nen luc waiting

		contentView.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View view) {
				
				//Create an Intent to start the ImageViewActivity
				Intent intent = new Intent(Waiting_screen.this, Voter_selecter.class);
				// Start the ImageViewActivity
				startActivity(intent);
				finish(); // Finish this activity, don't put it into stack.
			}
		});
	}

}
