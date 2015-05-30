package pufhcm.votepourenfants.screen_voter;


import java.util.ArrayList;
import pufhcm.votepourenfants.R;
import pufhcm.votepourenfants.Vote_screen;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnLongClickListener;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.TextView;

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

    /**
     * @param c
     * @param tlist : List of the image
     * @param imageOffset :position of the first image of the page
     * @param imageCount : Number of image in one page
     */
    public GridImageAdapter (Context c, List_image tlist, int imageOffset, int imageCount) {
        mContext = c;
        mFirstImgIndex = imageOffset;
        mImageCount = imageCount;
        mList_image = tlist;
        mNumImages = (tlist == null) ? 0 : mList_image.getNumVoter();
    }

    /**
     * Constructer of the Grid Image Adapter
     * @param c
     * @param tlist : List of the image
     * @param imageOffset :position of the first image of the page
     * @param imageCount : Number of image in one page
     * @param cellWidth
     * @param cellHeight
     * @param array : List of Integer for knowing the voter voted or doesn't vote yet
     */
    public GridImageAdapter (Context c, List_image tlist, int imageOffset, int imageCount, int cellWidth, 
    							int cellHeight, ArrayList<Integer> array) {
        this (c, tlist, imageOffset, imageCount);
        mCellWidth = cellWidth;
        mCellHeight = cellHeight;
        arr=array;
    }

    @Override
    public int getCount() {
        // how many image one page can show?
        int count = mImageCount;
        //The last page may be have less image than previous page 
        if (mFirstImgIndex + mImageCount >= mNumImages) count = mNumImages - mFirstImgIndex;
        return count;
    }

    @Override
    public Object getItem(int position) {
        return position; //i put somthing but that is not important
    }

    /* return the position od the image in the image list
     * @see android.widget.Adapter#getItemId(int)
     */
    @Override
    public long getItemId(int position) { //just let it here, but i don't use it
        return mFirstImgIndex + position;
    }

    // create a new ImageView for each item referenced by the Adapter
    @SuppressWarnings("deprecation")
	public View getView(int position, View convertView, ViewGroup parent) {
    	//day la phuong thuc rat quan trong boi chung ta xu ly, do du lieu tu day vao noi khac
    	// phuong thuc nay tra ve 1 view, view nay se dung de chung ta fill vao tung row cua list view hay tung o cua grid view
        ImageView imageView = null;
        TextView  textView  = null;
        View      childView = null;
        int numImages = mList_image.getNumVoter ();

        if (convertView == null) {  // if it's not recycled, initialize some attributes

           int layoutId = R.layout.page_grid_item;
           LayoutInflater li =  ((Activity) mContext).getLayoutInflater(); 
           childView = li.inflate (layoutId, null);
        } else {
            childView = convertView;
        }

        if (childView != null &&  convertView == null ) { //debug mut chi, moi thay thieu dieu kien la phai them convertview == null vao xu ly loi la hinh dau moi trang click long moi ra tag
           // Set the width and height of the child view.
           childView.setLayoutParams(new GridView.LayoutParams(mCellWidth, mCellHeight));
           childView.setBackgroundColor(0x0099cc);
           
           // poistion of the image in the list
           int j = position + mFirstImgIndex;
           if (j < 0) j = 0;
           if (j >= numImages) j = numImages - 1;
   
           imageView = (ImageView) childView.findViewById (R.id.image);
           if (imageView != null) {
        	  //take the image from the list image
              imageView.setImageResource (mList_image.IndexImage (j));
              imageView.setTag (Integer.valueOf(j) );

              int tick = arr.get(j);
              if(tick==1) ////if the voter doesnt' vote yet, image is set as nomal
              {
            	  imageView.setOnLongClickListener(new OnLongClickListener() {
            		  public boolean onLongClick(View v) {
            			  showImage ((Integer) v.getTag (),v);
                  
                  return true;
                }});
            	  }
              else { //if the voter was already voted, image is disable
            	  imageView.setAlpha(30);
            	  imageView.setRotationX(60);
            	  imageView.setScaleX((float) 0.8);
            	  imageView.setEnabled(false);
            	  }
           }
           
           //Show the name of the voter here
           textView = (TextView) childView.findViewById (R.id.voter_name);
           if (textView != null) {
              textView.setText(mList_image.getName (j)); 
           }
        }
        return childView;
    }

/**
 * showImage - start a GridImageActivity object to display the nth image.
 * end then disable image event click, modify image
 * after that, call the Vote Screen
 *
 * @param index int - the index number of the topic to display
 */

@SuppressWarnings("deprecation")
public void showImage (int index, View v) {

    arr.set(index, 0); // set 0 means this image has been click, use for orientation screen, data don't lost
    
    Intent intent = new Intent(mContext.getApplicationContext(), Vote_screen.class);
    intent.putExtra ("index", index);
    ((Activity)mContext).startActivityForResult (intent, 1);


    
    ((ImageView) v).setEnabled(false);
    ((ImageView) v).setAlpha(30);
    ((ImageView) v).setRotationX(60);
    ((ImageView) v).setScaleX((float) 0.8);
}

}

