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
   List_image imgList = new List_image (); //khoi tao voi truyen dong text o tren vao
   List_image.setInstance (imgList);//giu bien imgList thanh bien static

   // Create an adapter object that creates the fragments that we need 
   // to display the images and titles of all the topics.
   //Tao adapter, ma adapter nay se tao ra nhung vung chung ta can de
   // hien hinh anh va danh muc cua cac topic
   mAdapter = new MyAdapter (getSupportFragmentManager(), imgList, res); // coi ham o duoi  //Return the FragmentManager for interacting with fragments associated with this activity. 
   mPager = (ViewPager)findViewById(R.id.pager); //xem trong @layout/select_voter se thay id trong do
   mPager.setAdapter(mAdapter);// lay mAdapter lam adapter cho ViewPager nay

   // Save information about how many fragments are needed and how many items are on each page.
   int numImage = imgList.getNumVoter(); // trong Voter_information.java la 16 phan tu, chay tu 0->15
   int numRows = res.getInteger (R.integer.grid_num_rows); //doc thong so so dong, so cot trong Dimens.xml cua layout thich hop, //cho lenovo thi chinh sua layout Sw6000
   int numCols = res.getInteger (R.integer.grid_num_cols);
   int numImagePerPage = numRows * numCols; //1 trang se the hien bao nhieu hinh
   int numFragments = numImage / numImagePerPage; //co tong so hinh, va so hinh 1 trang, thi tinh ra ca can bao nhieu trang
   if (numImage % numImagePerPage != 0) numFragments++; // Vi chia lay phan nguyen, nen neu co phan du ra, thi ta phai tang them 1 trang de chua hinh
   mNumFragments = numFragments; //gan gia tri vua tinh toan vao bien chung, tong so trang can thiet
   mNumItems = numImagePerPage; // so hinh cua 1 trang, dua vao bien chung

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
 * Respond to a long click in one of the image views. Co the xoa luon cho nay
 * 
 * @param v View
 * @return boolean - true indicates that it was handled.
 */

public boolean onLongClick (View v) {
    Integer num = (Integer) v.getTag ();
    int index = num.intValue (); // cach viet trong Java <5, bay gio la Jav 7 hay 8, nen khong can thiet
    showTopic (index);
    return true;
} 
/**
 * showTopic - start a GridImageActivity object to display the nth topic.
 *
 * @param index int - the index number of the topic to display
 */

public void showTopic (int index) {

    //Toast.makeText (this, "thu nghiem " + index, Toast.LENGTH_SHORT).show(); //Toast la mot dang thong bao ngan, hien ra thong tin, thuong de thong bao gi do
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
    Bundle args = new Bundle(); // day la phan de dua vao thong so ve hinh de ma khi bam vao hinh, no se hien ra
    args.putInt("num", position+1); // so trang hien tai dang xet
    args.putInt("firstImage", position * mNumItems); //hinh dau tien cua trang dang xet la hinh co so thu tu nao :0,6,12..( neu 1 trang co 6 hinh)

    // Trang cuoi cung co the khong co du so hinh
//    int imageCount = mNumItems; //so hinh cua 1 trang
//    if (position == (mNumFragments-1)) { // phai tru di 1, vi position la so trang theo mang, tu 0 tro di, con mNum la so trang tong cong
//       int numImage = mList_image.getNumVoter(); // lai la tong so hinh
//       int rem = numImage % mNumItems;
//       if (rem > 0) imageCount = rem; //so hinh du thua de qua trang moi
//    }       
//    args.putInt("imageCount", imageCount); //dua vao so hinh du thua de qua trang moi
    args.putSerializable ("List_image", List_image.getInstance ());

    // Return a new GridFragment object.
    Page_grid f = new Page_grid ();  // coi trong Page_grid.java
    f.setArguments(args);
    return f;
}

/**
 * Thiet lap thong so cho Adapter tu List_image and resources object. kieu kieu giong ham Constructeur
 * Sau khi method hoan tat, tat ca instance variables cua adapter deu duoc thiet lap day du
 * 
 * @param imgList List_image
 * @param res Resources
 * @return void
 */

void setup (List_image imgList, Resources res) {
    mList_image = imgList;

    if ((imgList == null) || (res == null)) {
       mNumItems = DEFAULT_NUM_ITEMS;
       mNumFragments = DEFAULT_NUM_FRAGMENTS;
    } else {
      int numImage = imgList.getNumVoter();
      int numRows = res.getInteger (R.integer.grid_num_rows);
      int numCols = res.getInteger (R.integer.grid_num_cols);
      int numImagePerPage = numRows * numCols;
      int numFragments = numImage / numImagePerPage;
      if (numImage % numImagePerPage != 0) numFragments++; 
      
      mNumFragments = numFragments;
      mNumItems = numImagePerPage;
    }

    Log.d ("GridViewPager", "Num fragments, topics per page: " + mNumFragments + " " + mNumItems); //for debug

} // end setup

} // end class MyAdapter

	
	

}
