package pufhcm.votepourenfants;

import pufhcm.votepourenfants.screen_voter.List_image;
import pufhcm.votepourenfants.screen_voter.Page_grid;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentStatePagerAdapter;
import android.support.v4.view.ViewPager;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class Voter_selecter extends FragmentActivity implements View.OnLongClickListener{
	
	static final int DEFAULT_NUM_FRAGMENTS = 4;
    static final int DEFAULT_NUM_ITEMS = 4;

    MyAdapter mAdapter;
    ViewPager mPager;
    int mNumFragments = 0;       // total number of fragments
    int mNumItems = 0;           // number of items per fragment

/**
 * onCreate 
 * Create a set of views from a FragmentPagerAdapter object.
 * Arrange for those views to be displayed by a ViewPager view.
 */

@Override protected void onCreate(Bundle savedInstanceState) {
   super.onCreate(savedInstanceState);
   setContentView(R.layout.select_voter);

   Resources res = getResources ();// doc resource de su dung sau nay khoi viet dai dong

   // Create a List_image for this demo. Save it as the shared instance in List_image
   //String sampleText = res.getString (R.string.sample_topic_text); // lay cai dong text trong String ra
   List_image tlist = new List_image (); //khoi tao voi truyen dong text o tren vao
   List_image.setInstance (tlist);//giu bien tlist thanh bien static

   // Create an adapter object that creates the fragments that we need 
   // to display the images and titles of all the topics.
   //Tao adapter, ma adapter nay se tao ra nhung vung chung ta can de
   // hien hinh anh va danh muc cua cac topic
   mAdapter = new MyAdapter (getSupportFragmentManager(), tlist, res); // coi ham o duoi  //Return the FragmentManager for interacting with fragments associated with this activity. 
   mPager = (ViewPager)findViewById(R.id.pager); //xem trong @layout/demo_pager se thay id trong do
   mPager.setAdapter(mAdapter);

   // Save information about how many fragments are needed and how many items are on each page.
   int numTopics = tlist.getNumVoter(); // trong TestTopics.java la 16 phan tu
   int numRows = res.getInteger (R.integer.grid_num_rows); //doc thong so so dong, so cot trong Dimens.xml cua layout thich hop, //cho lenovo thi chinh sua layout Sw6000
   int numCols = res.getInteger (R.integer.grid_num_cols);
   int numTopicsPerPage = numRows * numCols; //1 trang co bao nhieu toppics
   int numFragments = numTopics / numTopicsPerPage;
   if (numTopics % numTopicsPerPage != 0) numFragments++; // Add one if there is a partial page
   mNumFragments = numFragments; //so fragment cung la so trang, dua vao bien chung
   mNumItems = numTopicsPerPage; // so topics cho 1 trang, dua vao bien chung

   // Watch for button clicks on the first and last buttons.
  /* Button button = (Button)findViewById(R.id.goto_first);
   button.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                mPager.setCurrentItem(0);
            }
   });
   button = (Button)findViewById(R.id.goto_last);
   button.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                mPager.setCurrentItem (mNumFragments-1);
            }
        });*/
    }

/**
 * Respond to a long click in one of the topic views.
 * 
 * @param v View
 * @return boolean - true indicates that it was handled.
 */

public boolean onLongClick (View v) {
    Integer num = (Integer) v.getTag ();
    int index = num.intValue (); // cach viet trong Java <5, bay gio la Jav 7 hay 8, nen khong can thiet
    showTopic (index);
    return true;
} // end onLongClick

/**
 * showTopic - start a GridImageActivity object to display the nth topic.
 *
 * @param index int - the index number of the topic to display
 */

public void showTopic (int index) {

    //Toast.makeText (this, "" + index, Toast.LENGTH_SHORT).show(); //Toast la mot dang thong bao ngan, hien ra thong tin, thuong de thong bao gi do
    //Intent intent = new Intent (this.getApplicationContext(), GridImageActivity.class); // khi bam click long, thi se hien ra layout khac, hien hinh to ra
    //intent.putExtra ("index", index);
    //this.startActivity (intent);
}


/**
 * Adapter class
 *
 * This adapter class sets up GridFragment objects to be displayed by a ViewPager.
 */

public static class MyAdapter extends FragmentStatePagerAdapter {

private List_image mList_image;
private int mNumItems = 0;
private int mNumFragments = 0;

/**
 * Return a new adapter.
 */

public MyAdapter (FragmentManager fm, List_image db, Resources res) {
    super(fm);
    setup (db, res);
}

/**
 * Get the number of fragments  to be displayed in the ViewPager.
 */

@Override public int getCount() {
    return mNumFragments;
}

/**
 * Return a new GridFragment that is used to display n items at the position given.
 *
 * @param position int - the position of the fragement; 0..numFragments-1
 */

@Override public Fragment getItem(int position) {
    //Create a new Fragment and supply the fragment number, image position, and image count as arguments.
    // (This was how arguments were handled in the original pager example.)
    Bundle args = new Bundle();
    args.putInt("num", position+1);
    args.putInt("firstImage", position * mNumItems);

    // The last page might not have the full number of items.
    int imageCount = mNumItems;
    if (position == (mNumFragments-1)) {
       int numTopics = mList_image.getNumVoter();
       int rem = numTopics % mNumItems;
       if (rem > 0) imageCount = rem;
    }       
    args.putInt("imageCount", imageCount);
    args.putSerializable ("List_image", List_image.getInstance ());

    // Return a new GridFragment object.
    Page_grid f = new Page_grid ();  // coi trong GridFragment.java
    f.setArguments(args);
    return f;
}

/**
 * Set up the adapter using information from a List_image and resources object.
 * When this method completes, all the instance variables of the adapter are valid;
 * 
 * @param tlist List_image
 * @param res Resources
 * @return void
 */

void setup (List_image tlist, Resources res) {
    mList_image = tlist;

    if ((tlist == null) || (res == null)) {
       mNumItems = DEFAULT_NUM_ITEMS;
       mNumFragments = DEFAULT_NUM_FRAGMENTS;
    } else {
      int numTopics = tlist.getNumVoter();
      int numRows = res.getInteger (R.integer.grid_num_rows);
      int numCols = res.getInteger (R.integer.grid_num_cols);
      int numTopicsPerPage = numRows * numCols;
      int numFragments = numTopics / numTopicsPerPage;
      if (numTopics % numTopicsPerPage != 0) numFragments++; // Add one if there is a partial page

      mNumFragments = numFragments;
      mNumItems = numTopicsPerPage;
    }

    Log.d ("GridViewPager", "Num fragments, topics per page: " + mNumFragments + " " + mNumItems);

} // end setup

} // end class MyAdapter

	
	

}
