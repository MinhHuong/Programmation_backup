package pufhcm.votepourenfants.screen_voter;

import pufhcm.votepourenfants.R;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.AdapterView.OnItemLongClickListener;


public class Page_grid extends Fragment{
	
	int mNum;                   // the id number assigned to this fragment
	int mFirstImage = 0;        // the index number of the first image to show in the fragment
	int mImageCount = -1;        // the number of images to show in the fragment
	List_image mList_image;       // the list of topics used by the fragment

	/**
	 * onCreate
	 */



	@Override public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

	   // Read the arguments and check resource values for number of rows and number of columns
	   // so we know how many images to display on this fragment.

	   Bundle args = getArguments ();
	   mNum = ((args != null) ? args.getInt ("num") : 0);

	   if (args != null) {
	      mList_image = (List_image) args.getSerializable ("List_image");
	      mFirstImage = args.getInt ("firstImage");
	   }
	   // mImageCount = ((args != null) ? args.getInt ("imageCount") : -1);

	   // Recalculate image count and then set mFirstImage to the first page that
	   // includes the old first image. We recalculate the image count because it might change
	   // if we are reorienting from portrait to landscape.
	   Resources res = getActivity ().getResources ();
	   int numRows = res.getInteger (R.integer.grid_num_rows);
	   int numCols = res.getInteger (R.integer.grid_num_cols);
	   int numTopicsPerPage = numRows * numCols;
	   mImageCount = numTopicsPerPage;

	   mFirstImage = (mFirstImage / numTopicsPerPage) * numTopicsPerPage;   // What happens as you re-orient? Might need to do better here.

	}

	/**
	 * onActivityCreated
	 * When the activity is created, divide the usable space into columns
	 * and put a grid of images in that area.
	 *
	 */

	@Override public void onActivityCreated(Bundle savedInstanceState) {
		super.onActivityCreated(savedInstanceState);

	   Activity a = getActivity ();
	   Resources res = a.getResources ();

	   View rootView = getView ();
		GridView gridview = (GridView) rootView.findViewById (R.id.gridview);

	   DisplayMetrics metrics = new DisplayMetrics();
	   a.getWindowManager().getDefaultDisplay().getMetrics(metrics);
/*
	   // From the resource files, determine how many rows and columns are to be displayed.
	   final int numRows = res.getInteger (R.integer.grid_num_rows);
	   final int numCols = res.getInteger (R.integer.grid_num_cols);

	   // Figure out how much space is available for the N rows and M columns to be displayed.
	   // We start with the root view for the fragment and adjust for the title, padding, etc.
	   int titleHeight = res.getDimensionPixelSize (R.dimen.topic_title_height);
	   int titlePadding = res.getDimensionPixelSize (R.dimen.topic_title_padding);
	   int buttonAreaHeight = res.getDimensionPixelSize (R.dimen.button_area_height);
	   int titleBarHeight = res.getDimensionPixelSize (R.dimen.title_bar_height);
	   int gridHspacing = res.getDimensionPixelSize (R.dimen.image_grid_hspacing);
	   int gridVSpacing = res.getDimensionPixelSize (R.dimen.image_grid_vspacing);
	   int otherGridH = res.getDimensionPixelSize (R.dimen.other_grid_h);
	   int otherGridW = res.getDimensionPixelSize (R.dimen.other_grid_w);
	   int heightUsed = 2*titleBarHeight + (numRows + 2) * gridVSpacing + (titleHeight + 2*titlePadding) 
	                    + otherGridH + buttonAreaHeight;

	   int widthUsed = 60;           // just a guess for now.
	   int availableHeight = metrics.heightPixels - heightUsed;    
	   int availableWidth = metrics.widthPixels - widthUsed;
	   int cellWidth = availableWidth / numCols;
	   int cellHeight = availableHeight / numRows;
*/
	   /* Put this back in to check the calculations for cell height and width.
	   Log.d ("Debug", "--- metrics h: " + metrics.heightPixels + "  w: " + metrics.widthPixels);
	   Log.d ("Debug", "    available h: " + availableHeight + "  w: " + availableWidth);
	   Log.d ("Debug", "    already used h: " + heightUsed + "  w: " + widthUsed);
	   Log.d ("Debug", "    cell h: " + cellHeight + "  w: " + cellWidth);
	   Log.d ("Debug", "--- num rows: " + numRows + "  cols: " + numCols);
	   Log.d ("Debug", "--- firstImage: " + mFirstImage + " image count: " + mImageCount);
	   */

	   if (gridview == null) Log.d ("DEBUG", "Unable to locate the gridview.");
	   else {
	        // Connect the gridview with an adapter that fills up the space.
	        gridview.setAdapter (new GridImageAdapter (a, mList_image, mFirstImage, mImageCount, R.integer.cell_width, R.integer.cell_height));

	        // Arrange it so a long click on an item in the grid shows the topic associated with the image.
	        gridview.setOnItemLongClickListener(new OnItemLongClickListener() {
	            public boolean onItemLongClick(AdapterView<?> parent, View v, int position, long id) {
	               showTopic (mFirstImage + position);
		            return true;
	            }
	        });

	   }
	}

	/**
	 * onCreateView
	 * Build the view that shows the grid.
	 */

	@Override public View onCreateView (LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
	   // Build the view that shows the grid.
		View view = inflater.inflate(R.layout.page_grid, container, false);

	   GridView gridview = (GridView) view.findViewById (R.id.gridview);
	   gridview.setTag (new Integer (mNum));

	   // Set label text for the view
//	   //View tv = view.findViewById (R.id.text);
//	   //if (tv != null) {
//	    //  ((TextView)tv).setText("Topics " + mNum);
//	   //}

	   // Hide the "no items" content until it is needed.
	   View nc = view.findViewById (R.id.no_topics_text);
	   if (nc != null) {
	      nc.setVisibility (View.INVISIBLE);   
	   }

		return view;
	}

	/**
	 * showTopic - start a GridImageActivity object to display the nth topic.
	 *
	 * @param index int - the index number of the topic to display
	 */

	public void showTopic (int index) {
/*
	    Toast.makeText(getActivity (), "" + index, Toast.LENGTH_SHORT).show();
	    Intent intent = new Intent(getActivity().getApplicationContext(), GridImageActivity.class);
	    intent.putExtra ("index", index);
	    startActivity (intent);*/
	}
/*	
	class GridImageAdapter extends BaseAdapter {

	    public static final int DEFAULT_CELL_SIZE = 220;  // default value to use for image width and height.

	    private Context mContext;
	    private List_image mList_image;
	    private int mImageOffset = 0;      // the index offset into the list of images
	    private int mImageCount = -1;      // -1 means that we display all images
	    private int mNumTopics  = 0;       // the total number of topics in the topics collection
	    private int mCellWidth = DEFAULT_CELL_SIZE;
	    private int mCellHeight = DEFAULT_CELL_SIZE;

	    public GridImageAdapter (Context c, List_image tlist, int imageOffset, int imageCount) {
	        mContext = c;
	        mImageOffset = imageOffset;
	        mImageCount = imageCount;
	        mList_image = tlist;
	        mNumTopics = (tlist == null) ? 0 : mList_image.getNumVoter ();
	    }

	    public GridImageAdapter (Context c, List_image tlist, int imageOffset, int imageCount, int cellWidth, int cellHeight) {
	        this (c, tlist, imageOffset, imageCount);
	        mCellWidth = cellWidth;
	        mCellHeight = cellHeight;
	    }

	    public int getCount() {
	        // If we are on the last page and there are no more images, the count is how many are being
	        // displayed.
	        int count = mImageCount;
	        if (mImageOffset + mImageCount >= mNumTopics) count = mNumTopics - mImageOffset;
	        return count;
	    }

	    public Object getItem(int position) {
	        return null;
	    }

	    public long getItemId(int position) {
	        return mImageOffset + position;
	    }

	    // create a new ImageView for each item referenced by the Adapter
	    public View getView(int position, View convertView, ViewGroup parent) {
	        ImageView imageView = null;
	        TextView  textView  = null;
	        View      childView = null;
	        int numTopics = mList_image.getNumVoter ();

//	        if (convertView == null) {  // if it's not recycled, initialize some attributes

//	           int layoutId = R.layout.page_grid_item;
//	           LayoutInflater li =  ((Activity) mContext).getLayoutInflater();
//	           childView = li.inflate (layoutId, null);
//	        } else {
	            childView = convertView;
//	        }

	        if (childView != null) {
	           // Set the width and height of the child view.
	           childView.setLayoutParams(new GridView.LayoutParams(mCellWidth, mCellHeight));

	           int j = position + mImageOffset;
	           if (j < 0) j = 0;
	           if (j >= numTopics) j = numTopics - 1;
	   
	           imageView = (ImageView) childView.findViewById (R.id.image);
	           if (imageView != null) {
	              Resources res = mContext.getResources ();
	              int imagePadding = res.getDimensionPixelSize (R.dimen.grid_image_padding);

	              imageView.setScaleType(ImageView.ScaleType.CENTER_CROP);
	              imageView.setBackgroundResource (R.color.background_grid1_cell);
	              imageView.setPadding (imagePadding, imagePadding, imagePadding, imagePadding);
	              imageView.setImageResource (mList_image.IndexImage (j));
	              imageView.setTag (new Integer (j));
	              // imageView.setOnLongClickListener ((View.OnLongClickListener) mContext);
	              
	              imageView.setOnLongClickListener(new OnLongClickListener() {
	                public boolean onLongClick(View v) {
	                  showTopic ((Integer) v.getTag ());
	                  return true;
	                }
	              });
	              

	           }
	           textView = (TextView) childView.findViewById (R.id.title);
	           if (textView != null) {
	              textView.setText(mList_image.getName (j)); 
	              textView.setTag (new Integer (j));
	              /*
	              textView.setOnLongClickListener(new OnLongClickListener() {
	                public boolean onLongClick(View v) {
	                  showTopic ((Integer) v.getTag ());
	                  return true;
	                }
	              });
	              
	           }
	        }
	        return childView;
	    }


	}
*/
}