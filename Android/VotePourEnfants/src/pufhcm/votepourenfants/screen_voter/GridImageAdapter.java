package pufhcm.votepourenfants.screen_voter;

import java.lang.reflect.Array;
import java.util.ArrayList;

import pufhcm.votepourenfants.R;
import pufhcm.votepourenfants.Resultat_screen;
import pufhcm.votepourenfants.Vote_screen;
import pufhcm.votepourenfants.Voter_selecter;
import android.R.bool;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.res.Resources;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnLongClickListener;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

/**
 * @author Sa Doa Tien Sinh
 *
 */
public class GridImageAdapter extends BaseAdapter {

    public static final int DEFAULT_CELL_SIZE = 300;  // default value to use for image width and height.

    private Context mContext;
    private List_image mList_image;
    private int mFirstImgIndex = 0;      // the index offset into the list of images
    private int mImageCount = -1;      // -1 means that we display all images
    private int mNumImages  = 0;       // the total number of Images in the Images collection
    private int mCellWidth = DEFAULT_CELL_SIZE;
    private int mCellHeight = DEFAULT_CELL_SIZE;
    private ArrayList<Integer> arr;
    private ArrayList<Integer> number_vote;

    /**
     * @param c
     * @param tlist
     * @param imageOffset
     * @param imageCount
     */
    public GridImageAdapter (Context c, List_image tlist, int imageOffset, int imageCount) {
        mContext = c;
        mFirstImgIndex = imageOffset;
        mImageCount = imageCount;
        mList_image = tlist;
        mNumImages = (tlist == null) ? 0 : mList_image.getNumVoter();
    }

    public GridImageAdapter (Context c, List_image tlist, int imageOffset, int imageCount, int cellWidth, 
    							int cellHeight, ArrayList<Integer> array, ArrayList<Integer> num_vote) {
        this (c, tlist, imageOffset, imageCount);
        mCellWidth = cellWidth;
        mCellHeight = cellHeight;
        arr=array;
        number_vote = num_vote;
    }

    @Override
    /* La phuong thuc de tra ve gia tri la so luong cac phan tu cua danh sach
     * @see android.widget.Adapter#getCount()
     */
    public int getCount() {
        // So hinh ma trang do se hien len
        int count = mImageCount;
        //Trang cuoi cung co the khong day du hinh        
        if (mFirstImgIndex + mImageCount >= mNumImages) count = mNumImages - mFirstImgIndex;
        return count;
    }

    @Override
    /* tra ve object tai vi tri position trong danh sach
     * @see android.widget.Adapter#getItem(int)
     */
    public Object getItem(int position) {
        return position;
    }

    /* tra ve Id cua moi item trong list
     * @see android.widget.Adapter#getItemId(int)
     */
    @Override
    public long getItemId(int position) { //methode de lam kieng, khong su dung den
        return mFirstImgIndex + position;
    }

    // create a new ImageView for each item referenced by the Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
    	//day la phuong thuc rat quan trong boi chung ta xu ly, do du lieu tu day vao noi khac
    	// phuong thuc nay tra ve 1 view, view nay se dung de chung ta fill vao tung row cua list view hay tung o cua grid view
        ImageView imageView = null;
       // ImageView imageView1 = null;
        TextView  textView  = null;
        View      childView = null;
        int numImages = mList_image.getNumVoter ();

        if (convertView == null) {  // if it's not recycled, initialize some attributes

           int layoutId = R.layout.page_grid_item;
           LayoutInflater li =  ((Activity) mContext).getLayoutInflater(); //set layout cho grid la layout page_grid_item
           childView = li.inflate (layoutId, null);
        } else {
            childView = convertView;
        }

        if (childView != null &&  convertView == null ) { //debug mut chi, moi thay thieu dieu kien la phai them convertview == null vao xu ly loi la hinh dau moi trang click long moi ra tag
           // Set the width and height of the child view.
        	//childView.invalidate();
           childView.setLayoutParams(new GridView.LayoutParams(mCellWidth, mCellHeight));
           childView.setBackgroundColor(0x0099cc);
           //childView.setEnabled(false);
           //childView.setAlpha(0);
           //childView.setClickable(false);;
           //mContext.
           
           int j = position + mFirstImgIndex;
           if (j < 0) j = 0;
           if (j >= numImages) j = numImages - 1;
   
           
           //imageView1.setAlpha(0);
           imageView = (ImageView) childView.findViewById (R.id.image);
           if (imageView != null) {
//              Resources res = mContext.getResources ();

              imageView.setImageResource (mList_image.IndexImage (j));
              imageView.setTag (Integer.valueOf(j) );
              // imageView.setOnLongClickListener ((View.OnLongClickListener) mContext);
             // imageView1 = (ImageView) childView.findViewById (R.id.tick_image);
              int tick = arr.get(j);
              if(tick==1)
              {//imageView1.setAlpha(0);
            	 //imageView.setEnabled(true);
              imageView.setOnLongClickListener(new OnLongClickListener() {
                public boolean onLongClick(View v) {
                  showImage ((Integer) v.getTag (),v);
                  
                  return true;
                }
              });}
              else {
            	  imageView.setAlpha(30);
            	  imageView.setRotationX(60);
            	  imageView.setScaleX((float) 0.8);
            	  imageView.setEnabled(false);
            	  //childView.setActivated(false);
            	  }// imageView1.setAlpha(50);}
           }
           
           textView = (TextView) childView.findViewById (R.id.voter_name);
           if (textView != null) {
              textView.setText(mList_image.getName (j)); 
       /*       textView.setTag (new Integer (j));
              
              textView.setOnLongClickListener(new OnLongClickListener() {
                public boolean onLongClick(View v) {
                  showImage ((Integer) v.getTag (), v);
                  return true;
                }
              });*/
              
           }
        }
        return childView;
    }

/**
 * showImage - start a GridImageActivity object to display the nth image.
 *
 * @param index int - the index number of the topic to display
 */

@SuppressWarnings("deprecation")
public void showImage (int index, View v) {

   // Toast.makeText(mContext, "Vi tri cua hinh la " + index, Toast.LENGTH_SHORT).show();
   // ((ImageView) v).setMaxWidth(100);
    //ImageView imageView1 = (ImageView) ((ImageView) v).findViewById (R.id.tick_image);
   // imageView1.setAlpha(150);
    //ImageView imageView = (ImageView)v.findViewById(R.id.tick_image);
    //imageView.setAlpha(180);
    
//    ((ImageView) v).setImageResource(R.drawable.tick);
    //((TextView) v).setEnabled(false);
	//int value0 = number_vote.get(0);
	//int value1 = number_vote.get(1);
	//int value2 = number_vote.get(2);
	//int value3 = number_vote.get(3);
   // Toast.makeText(mContext, "Vi tri cua hinh la " + value, Toast.LENGTH_SHORT).show();
    arr.set(index, 0);
    Intent intent = new Intent(mContext.getApplicationContext(), Vote_screen.class);
    intent.putExtra ("index", index);
    ((Activity)mContext).startActivityForResult (intent, 1);

   // Intent a = new Intent(mContext.getApplicationContext(),null);
   // ((Activity)mContext).onActivityReenter(1, a);
  //  int ordinal = a.getIntExtra("ordinal_number",0);
  //  int va = number_vote.get(0);
    //Toast.makeText(mContext, "Vi tri cua hinh la " + va, Toast.LENGTH_SHORT).show();
  //  int valu = number_vote.get(ordinal);
  //  valu++;
  //  number_vote.set(ordinal, valu);
   // String str = (mContext).getResources().toString();
   // int tick = arr.get(index);

    //((Voter_selecter)mContext).setArray(index);
    
    ((ImageView) v).setEnabled(false);
    ((ImageView) v).setAlpha(30);
    ((ImageView) v).setRotationX(60);
    ((ImageView) v).setScaleX((float) 0.8);
}

}

