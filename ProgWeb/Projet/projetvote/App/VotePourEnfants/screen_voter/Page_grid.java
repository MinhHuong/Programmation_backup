package pufhcm.votepourenfants.screen_voter;

import pufhcm.votepourenfants.R;
import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.GridView;

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

	   Bundle args = getArguments (); //nhan thong so argument tu class goi no la ben voter_selecter.java dong f.setArguments(arg)
	   mNum = ((args != null) ? args.getInt ("num") : 0); //lay ra thu tu trang de xet (bat dau la 1 chu khong phai 0)

	   if (args != null) {
	      mList_image = (List_image) args.getSerializable ("List_image"); //nhan vao danh sach hinh anh
	      mFirstImage = args.getInt ("firstImage"); //vi tri cua hinh dau tien cua trang (bat dau tu 0)
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
	        gridview.setAdapter (new GridImageAdapter (acti, mList_image, mFirstImage, mImageCount, R.integer.cell_width, R.integer.cell_height));
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
	 *Xay dung View ma hien grid ra
	 */

	@Override public View onCreateView (LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
	   // Build the view that shows the grid.
		View view = inflater.inflate(R.layout.page_grid, container, false); //don gian la tao 1 view co giao dien la file page_grid.xml, gan ket voi cha la container

//	   GridView gridview = (GridView) view.findViewById (R.id.gridview);
//	   gridview.setTag (new Integer (mNum));

	   // Set label text for the view
//	   //View tv = view.findViewById (R.id.text);
//	   //if (tv != null) {
//	    //  ((TextView)tv).setText("Topics " + mNum);
//	   //}

	   // Hide the "no items" content until it is needed.
//	   View nc = view.findViewById (R.id.no_topics_text); //tim view theo id do de set no khong nhin thay
//	   if (nc != null) {
//	      nc.setVisibility (View.VISIBLE);   
//	   }

		return view;
	}

	/**
	 * showTopic - start a GridImageActivity object to display the nth topic.
	 *
	 * @param index int - the index number of the topic to display
	 */

	public void showTopic (int index) {

	    //Toast.makeText(getActivity (), " tesssst" + index, Toast.LENGTH_SHORT).show();
	   /* Intent intent = new Intent(getActivity().getApplicationContext(), GridImageActivity.class);
	    intent.putExtra ("index", index);
	    startActivity (intent);*/
	}
	
}