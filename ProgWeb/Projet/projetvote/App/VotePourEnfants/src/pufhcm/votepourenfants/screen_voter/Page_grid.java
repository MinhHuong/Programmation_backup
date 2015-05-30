package pufhcm.votepourenfants.screen_voter;

import java.util.ArrayList;

import pufhcm.votepourenfants.R;
import android.R.array;
import android.app.Activity;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.GridView;
import android.widget.Toast;

public class Page_grid extends Fragment{
	
	int mNum;                   // the id number assigned to this fragment
	int mFirstImage = 0;        // the index number of the first image to show in the fragment
	int mImageCount = -1;        // the number of images to show in the fragment
	List_image mList_image;       // the list of topics used by the fragment
	 private static final String KEY_TICK_VALUE = "TICK";
	 private static final String NUMBER_VOTE = "NB";
	    ArrayList<Integer> array;
	    ArrayList<Integer> num_vote;
	    
	    public int getArray(int index) {
			return array.get(index);
		}
		public void setArray(int index) {
			this.array.set(index, 0) ;
		}
		
//		@Override
	/*	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		    if (data == null) {return;}
		    int ordinal = data.getIntExtra("ordinal_number",0);
		    int va = num_vote.get(0);
		    Toast.makeText(getActivity(), "Vi tri cua hinh la " + va, Toast.LENGTH_SHORT).show();
		    int value = num_vote.get(ordinal);
		    value++;
		    num_vote.set(ordinal, value);
//		    tvName.setText("Your name is " + name);
		  }
		@Override
		public void onSaveInstanceState (Bundle outState) {
	        super.onSaveInstanceState(outState);
	        outState.putIntegerArrayList(KEY_TICK_VALUE, array);
	        outState.putIntegerArrayList(NUMBER_VOTE, num_vote);
	    }
*/
	/**
	 * onCreate
	 */



	@Override public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		if (savedInstanceState != null) {
			   ArrayList<Integer> arr_tmp = savedInstanceState.getIntegerArrayList(KEY_TICK_VALUE);
			   array= arr_tmp;
			   ArrayList<Integer> num_vote_tmp = savedInstanceState.getIntegerArrayList(NUMBER_VOTE);
			   num_vote= num_vote_tmp;
			   }
		   else {
			   array = new ArrayList<Integer>();
			   num_vote = new ArrayList<Integer>();
			   for (int i = 0; i < Voter_information.ImageIds.length; i++)
				   array.add(1);
			   for (int i = 0; i < 4; i++)
				   num_vote.add(0);
		   }
	   // Read the arguments and check resource values for number of rows and number of columns
	   // so we know how many images to display on this fragment.
		//array = new ArrayList<Integer>();
		//for(int i = 0; i < 16; i++)
		//	array.add(1);
	   Bundle args = getArguments (); //nhan thong so argument tu class goi no la ben voter_selecter.java dong f.setArguments(arg)
	   mNum = ((args != null) ? args.getInt ("num") : 0); //lay ra thu tu trang de xet (bat dau la 1 chu khong phai 0)

	   if (args != null) {
	      mList_image = (List_image) args.getSerializable ("List_image"); //nhan vao danh sach hinh anh
	      mFirstImage = args.getInt ("firstImage"); //vi tri cua hinh dau tien cua trang (bat dau tu 0)
	      
	      array = args.getIntegerArrayList("status");
	      num_vote = args.getIntegerArrayList("count");
	   }
	   // mImageCount = ((args != null) ? args.getInt ("imageCount") : -1);

	   // Tinh toan lai so hinh cua 1 trang va sau do thiet lap mFirstImage
	   // Ta phai tinh toan lai vi co the se thay doi neu ta xoay man hinh tu dung sang nam ngang hoac nguoc lai
	   // Nhung neu xoay ma tong so hinh cua 1 trang van nhu nhau, thi co the bo qua buoc nay
	   //can nghien cuu lai
	   Resources res = getActivity ().getResources (); 
	   int numRows = res.getInteger (R.integer.grid_num_rows);
	   int numCols = res.getInteger (R.integer.grid_num_cols);
	   int numTopicsPerPage = numRows * numCols;
	   mImageCount = numTopicsPerPage;

	   mFirstImage = (mFirstImage / numTopicsPerPage) * numTopicsPerPage;   // What happens as you re-orient? Might need to do better here.

	}

	/**
	 * onActivityCreated
	 * Khi ma activity duoc tao, thi phan vung su dung duoc ra thanh nhung cot
	 * va de nhung grid image va vi tri do
	 *
	 */

	@Override public void onActivityCreated(Bundle savedInstanceState) {
		super.onActivityCreated(savedInstanceState);

	   Activity acti = getActivity ();
	   //Resources res = a.getResources ();

	   View rootView = getView (); 
		GridView gridview = (GridView) rootView.findViewById (R.id.gridview);

	  // DisplayMetrics metrics = new DisplayMetrics(); //mot cau truc cua adroid de biet thiet bi co nhung dac tinh gi: vi du kich co man hinh, do phan giai...
	   //a.getWindowManager().getDefaultDisplay().getMetrics(metrics);

	   if (gridview == null) Log.d ("DEBUG", "Unable to locate the gridview."); // dung de log lai, debug loi cho de dang
	   else {
	        // ket noi voi gridview bang adapter 
	        gridview.setAdapter (new GridImageAdapter (acti, mList_image, mFirstImage, mImageCount, R.integer.cell_width, R.integer.cell_height, array));
	        //hay co the su dung cau lenh nay, nhung se  phai chinh kich co cell ben GridImageAdapter.java
	        //muon chinh kich co hinh, ta phai chinh kich co cua cell, roi moi den kich co cua hinh trong dimens.xml
	        //gridview.setAdapter (new GridImageAdapter (acti, mList_image, mFirstImage, mImageCount));
	        // Arrange it so a long click on an item in the grid shows the topic associated with the image.
	       /* gridview.setOnItemLongClickListener(new OnItemLongClickListener() {
	            public boolean onItemLongClick(AdapterView<?> parent, View v, int position, long id) {
	               showTopic (mFirstImage + position);
		            return true;
	            }
	        });*/

	   }
	}

	/**
	 * onCreateView
	 * This View contain the grid for list image
	 */

	@Override public View onCreateView (LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
		View view = inflater.inflate(R.layout.page_grid, container, false); //don gian la tao 1 view co giao dien la file page_grid.xml, gan ket voi cha la container


		return view;
	}
}