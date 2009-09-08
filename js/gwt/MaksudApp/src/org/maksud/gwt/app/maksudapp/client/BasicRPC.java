package org.maksud.gwt.app.maksudapp.client;

import java.util.List;

import org.maksud.gwt.app.maksudapp.client.overlay.*;

import com.extjs.gxt.ui.client.data.BasePagingLoadResult;
import com.google.gwt.core.client.GWT;
import com.google.gwt.user.client.rpc.RemoteService;
import com.google.gwt.user.client.rpc.RemoteServiceRelativePath;

@RemoteServiceRelativePath("BasicRPC")
public interface BasicRPC extends RemoteService {
	/**
	 * Utility class for simplifying access to the instance of async service.
	 */
	public static class Util {
		private static BasicRPCAsync instance;

		public static BasicRPCAsync getInstance() {
			if (instance == null) {
				instance = GWT.create(BasicRPC.class);
			}
			return instance;
		}
	}

	List<UserEntity> getUsers();

	List<Employee> getEmployees();

}
